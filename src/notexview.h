
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

    void hook_idle();

    bool scan_for_tex();
    int render_tex(const Glib::ustring& text, int num_rendered,
                                                        std::string& filename);

protected:
    Gtk::TextView m_textview;
    int m_count;

};
