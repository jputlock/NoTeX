
#include <gtkmm.h>
#include <iostream>
#include <pangomm.h>
#include <string>
#include <sys/wait.h>
#include <unistd.h>
#include <list>

#include "clickableimage.h"

class NotexView : public Gtk::ScrolledWindow {
public:
	NotexView();
	virtual ~NotexView();

	void set_text(const std::string& text);
	const std::string get_text();

	void hook_idle();
	void on_resize();

	bool scan_tex_full();

	int render_tex(const Glib::ustring& text, int num_rendered, std::string& filename);
	void recover_tex(Gtk::TextChildAnchor& anchor);

protected:
	Gtk::TextView m_textview;
	int m_count;
	unsigned int font_size;
	std::list<Gtk::TextChildAnchor> anchors;
	std::list<std::string> imported_packages;
};
