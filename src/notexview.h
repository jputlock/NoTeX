
#include <gtkmm.h>
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <string>

#include "clickableimage.h"

class NotexView : public Gtk::ScrolledWindow {
public:
    NotexView ();
    virtual ~NotexView();

    void set_text(const std::string& text);
    const std::string get_text();

    void scan_for_tex(const Gtk::TextBuffer::iterator& pos,
                                    const Glib::ustring& inserted, int bytes);
    int render_tex(const Glib::ustring& text, int num_rendered,
                                                        std::string& filename);

protected:
    Gtk::TextView m_textview;

};
