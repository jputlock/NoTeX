
#include "notexview.h"

#include "include/pdf2svg/pdf2svg.c"

NotexView::NotexView() : Gtk::ScrolledWindow() {
    this->set_hexpand(false);
    this->set_vexpand(true);
    this->set_size_request(1000, 1000);
    this->show();

    this->m_textview.set_editable(true);
    this->m_textview.set_cursor_visible(true);
    this->m_textview.show();

    this->m_textview.set_size_request (-1, -1);
    this->m_textview.set_wrap_mode(Gtk::WRAP_WORD);
    auto textBuffer = Gtk::TextBuffer::create();

    this->m_textview.set_buffer(textBuffer);

    // textBuffer->signal_insert().connect(sigc::mem_fun(*this,
        // &NotexView::scan_for_tex));

    Glib::signal_idle().connect( sigc::mem_fun(*this, &NotexView::scan_for_tex) );

    this->m_count = 0;
    this->add(m_textview);
}

NotexView::~NotexView() { }

bool NotexView::scan_for_tex() {
    auto textBuffer = this->m_textview.get_buffer();

    // todo: implement the data structure to add marks where start/end points are

    size_t start = 0, end = 0;

    // iterate through the buffer
    start = textBuffer->get_text().find("\\(");
    if (start == std::string::npos) {
        return true;
    }
    end = textBuffer->get_text().find("\\)");
    if (end == std::string::npos) {
        return true;
    }
    end += 2;

    // shift the indices by the number of pictures before it
    for (int i = 0; i < start; i++) {
        if (textBuffer->get_iter_at_offset(i).get_char() == 0xFFFC ) {
            start++;
            end++;
        }
    }

    // grab the iterators at the locations
    auto start_iter = textBuffer->get_iter_at_offset(start);
    auto end_iter = textBuffer->get_iter_at_offset(end);

    std::string tex = textBuffer->get_text(start_iter, end_iter);

#ifdef DEBUG
    std::cout << "Rendering \"" + tex + "\"" << std::endl;
#endif

    std::string filename;
    this->render_tex(tex, this->m_count, filename);
    std::cout << "filename = " << filename << std::endl;

    // note: this mark doesnt follow the picture if text inserted in the exact char before the picture
    // but this shouldn't be an issue once we implement picture -> tex functionality
    auto mark_start = textBuffer->create_mark("startTex" + this->m_count, start_iter);
    auto mark_end = textBuffer->create_mark("endTex", end_iter);

    this->m_count++;

    textBuffer->erase(mark_start->get_iter(), mark_end->get_iter());

#ifdef DEBUG
    std::cout << "\nNew text:" << textBuffer->get_text() << std::endl;
#endif

    auto img = Gtk::make_managed<ClickableImage>(filename, tex);

    // todo: cleanup ClickableImage, Anchor, and Mark on deletion
    auto anc = textBuffer->create_child_anchor(mark_start->get_iter());
    this->m_textview.add_child_at_anchor(*img, anc);
    img->show();

    // mark_start->set_visible(true);

    textBuffer->delete_mark(mark_end);

    return true;
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

    /* todo: append \\usepackage {package} for each package included at the top */
    auto new_text = "\\documentclass{standalone}\\usepackage{amsmath}\\begin{document}"
                                                    + text + "\\end{document}";

    char* tex_to_compile = (char*) new_text.data();

    filename = "temp" + std::to_string(num_rendered) + ".svg";
    char* file_out = (char*) filename.data();

    int pid = fork();

    // child
    if (pid == 0){
        char* args[] = {(char*)"pdflatex", (char*)"-interaction=nonstopmode",
                                (char*)"-halt-on-error", tex_to_compile, NULL};

        // call PDFLatex to compile into a standalone PDF
        int exit_code = execvp(args[0], args);

        return exit_code;

    }
    int status;

    // wait until the PDF is compiled
    waitpid(pid, &status, 0);
    if (status == -1){
        perror("PDF compilation failed");
        return status;
    }

    char* pdf_name = (char*)"standalone.pdf";

    char* args[] = {(char*)"pdf2svg", pdf_name, file_out, NULL};

    int exit_code = pdf2svg(3, args);

    // Wait for the SVG to be generated
    if (status == -1){
        perror("SVG generation failed");
        return status;
    }

    pid = fork();
    if(pid == 0){

        char* args[] = {(char*)"rm", (char*)"standalone.aux",
                        (char*)"standalone.pdf", (char*)"standalone.log", NULL};
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
