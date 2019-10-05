//
// Created by jputlock on 7/14/19.
//

#include <gtkmm/eventbox.h>
#include <gtkmm/image.h>

class ClickableImage : public Gtk::EventBox {
protected:
	Gtk::Image img;
	Glib::ustring tex_contents;

public:
	ClickableImage(const std::string& file_name, const Glib::ustring& tex)
		: Gtk::EventBox() {
		// add the image
		this->img.set(file_name);
		this->add(img);
		this->img.show();

		// add the click event
		this->signal_button_press_event().connect(
			sigc::mem_fun(*this, &ClickableImage::on_button_press_event));

		this->set_tooltip_text("Click me!");

		// allow events
		this->set_events(Gdk::BUTTON_PRESS_MASK);
	}

	bool on_button_press_event(GdkEventButton* button_event) {
		// do something
		this->set_tooltip_text("This has been clicked.");
		return true;
	}
};
