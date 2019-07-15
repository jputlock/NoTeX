
#include <gtkmm/eventbox.h>
#include <gtkmm/image.h>

class ClickableImage : public Gtk::EventBox {
protected:
    Gtk::Image img;

public:
    ClickableImage(const std::string& file_name) : Gtk::EventBox() {
        this->img = Gtk::Image(file_name);
        this->add(img);
        this->img.show();
        this->signal_button_press_event().connect(sigc::mem_fun(*this, &ClickableImage::on_button_press_event));
        this->set_tooltip_text("Click me!");
        this->set_events(Gdk::BUTTON_PRESS_MASK);
    }

    bool on_button_press_event(GdkEventButton* button_event) {
        // do something
        this->set_tooltip_text("This is a test.");
        return true;
    }
};
