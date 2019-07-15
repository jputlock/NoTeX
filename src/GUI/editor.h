//
// Created by jputlock on 6/1/19.
//

#ifndef NOTEX_EDITOR_H
#define NOTEX_EDITOR_H

#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/textview.h>
#include <gtkmm/box.h>

#include "clickableimage.h"

class Editor : public Gtk::Window {

public:
    Editor();
    virtual ~Editor();

protected:
    //Signal handlers:
    void on_button_clicked();

    //Member widgets:
    ClickableImage m_img;
    Gtk::Box m_box;
    Gtk::Button m_button;
    Gtk::TextView m_textview;
};



#endif //NOTEX_EDITOR_H
