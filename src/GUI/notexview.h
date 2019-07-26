
#include <gtkmm.h>

class NotexView : public Gtk::ScrolledWindow {
public:
    NotexView ();
    virtual ~NotexView();

    void set_text(const std::string& text);
    const std::string get_text();

protected:
    Gtk::TextView m_textview;

};
