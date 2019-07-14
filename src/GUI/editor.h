//
// Created by jputlock on 6/1/19.
//

#ifndef NOTEX_EDITOR_H
#define NOTEX_EDITOR_H

#include <gtkmm/window.h>
#include <gtkmm/button.h>

class Editor : public Gtk::Window
{

public:
    Editor();
    virtual ~Editor();

protected:
    //Signal handlers:
    void on_button_clicked();

    //Member widgets:
    Gtk::Button m_button;
};



#endif //NOTEX_EDITOR_H
