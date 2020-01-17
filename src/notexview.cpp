
#include "notexview.h"
#include <regex>

#include "include/pdf2svg/pdf2svg.c"

NotexView::NotexView() : Gtk::ScrolledWindow() {
	this->set_hexpand(true);
	this->set_vexpand(true);

	this->set_size_request(-1, -1);
	this->show();

	this->font_size = 12;

	// make the view resizable
	this->signal_check_resize().connect(
		sigc::mem_fun(*this, &NotexView::on_resize));

	this->m_textview.set_editable(true);
	this->m_textview.set_cursor_visible(true);
	this->m_textview.show();

	this->m_textview.set_size_request(-1, -1);
	this->m_textview.set_wrap_mode(Gtk::WRAP_WORD);
	auto textBuffer = Gtk::TextBuffer::create();

	this->m_textview.set_buffer(textBuffer);

	// create a larger font
	Pango::FontDescription font =
		this->m_textview.get_style_context()->get_font();

	font.set_size(Pango::SCALE * font_size);
	this->m_textview.override_font(font);

	// create the updater hook
	textBuffer->signal_end_user_action().connect(
		sigc::mem_fun(*this, &NotexView::hook_idle));

	this->m_count = 0;
	this->add(m_textview);
}

void NotexView::on_resize() {
	Container* editor = this->get_parent();

	if (editor) {

		// initialize just in case
		int width = -1, height = -1;

		// grab the editor's size
		width = editor->get_allocated_width();
		height = editor->get_allocated_height();

		this->set_size_request(width, height);

#ifdef DEBUG
		std::cout << "view resized!" << std::endl;
#endif
	}
}

void NotexView::hook_idle() {
	Glib::signal_idle().connect(sigc::mem_fun(*this, &NotexView::scan_for_tex));
}

NotexView::~NotexView() {
#ifdef DEBUG
	std::cout << "Deleting NotexView" << std::endl;
#endif
}

bool NotexView::scan_tex_full() {
	Gtk::TextBuffer textBuffer = this->m_textview.get_buffer();

	// get packages
	std::regex package_finder("\\usepackage(\[.*?\])?\{.*?\}");

	// identify tex chunks

	// these find starts and ends
	std::regex tex_inline_mm("[^\\](\$)|^(\$)");
	std::regex tex_std_mm("[^\\](\$\$)|^(\$\$)");

	// these will conveniently find full chunks
	std::regex latex_inline_mm("\\\(.*?\\\)");
	std::regex latex_std_mm("\\\[.*?\\\]");

	

}

void NotexView::recover_tex(Gtk::TextChildAnchor& anchor) {

}

/** @brief Converts a string of TeX into an SVG at file denoted by string
 * file_out.
 *
 * @param text - TeX to compile to TeX
 *
 * The TeX is converted into a pdf via PDFLatex and then converted from PDF
 * to SVG via the open source PDF to SVG converter, pdf2svg.
 *
 * @return the exit code denoting whether or not it was successful.
 *
 */
int NotexView::render_tex(const Glib::ustring& text, int num_rendered,
						  std::string& filename) {
	/* todo: append \\usepackage {package} for each package included at the top
	 */
	auto new_text = "\\documentclass[20pt]{standalone}\\usepackage{amsmath}"
					"\\begin{document}\\Large" +
					text + "\\end{document}";

	char* tex_to_compile = (char*)new_text.data();

	filename = "temp" + std::to_string(num_rendered) + ".svg";
	char* file_out = (char*)filename.data();


	// todo: don't use fork i guess??
	int pid = fork();

	// child
	if (pid == 0) {

		// todo: collect their latex install location from settings
		char* args[] = {(char*)"pdflatex", (char*)"-interaction=nonstopmode",
						(char*)"-halt-on-error", tex_to_compile, NULL};

		// call PDFLatex to compile into a standalone PDF
		int exit_code = execvp(args[0], args);

		return exit_code;
	}
	int status;

	// wait until the PDF is compiled
	waitpid(pid, &status, 0);
	if (status == -1) {
		perror("PDF compilation failed");
		return status;
	}

	char* pdf_name = (char*)"standalone.pdf";

	char* args[] = {(char*)"pdf2svg", pdf_name, file_out, NULL};

	int exit_code = pdf2svg(3, args);

	// Wait for the SVG to be generated
	if (status == -1) {
		perror("SVG generation failed");
		return status;
	}

	pid = fork();
	if (pid == 0) {
		char* args[] = {(char*)"rm", (char*)"standalone.aux",
						(char*)"standalone.pdf", (char*)"standalone.log", &filename[0], NULL};
		int exit_code = execvp(args[0], args);

		return exit_code;
	}

	std::cout << "Operation finished. See \"" << file_out << "\"" << std::endl;

	return EXIT_SUCCESS;
}

void NotexView::set_text(const std::string& text) {
	this->m_textview.get_buffer()->set_text(text);
}

const std::string NotexView::get_text() {
	return this->m_textview.get_buffer()->get_text();
}
