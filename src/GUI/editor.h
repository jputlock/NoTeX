//
// Created by jputlock on 6/1/19.
//

#ifndef NOTEX_EDITOR_H
#define NOTEX_EDITOR_H

#include <gtkmm.h>
#include <iostream>

#include "clickableimage.h"

class Editor : public Gtk::ApplicationWindow {

public:
    Editor();
    virtual ~Editor();

protected:
    //Signal handlers:
    void on_button_clicked();

    //Member widgets:
    ClickableImage m_img;

    Gtk::Fixed m_fixed;
    Gtk::Button m_button;
    Gtk::TextView m_textview;

    // menubar items
    Gtk::MenuBar m_menuBar;
    Gtk::MenuItem m_menuFile;
    Gtk::Menu m_subMenuFiles;
    Gtk::MenuItem m_menuNew, m_menuOpen, m_menuSave;

    // in case we need a separator in the submenu
    Gtk::SeparatorMenuItem hline;
private:
    void on_menu_file_new();
    void on_menu_file_open();
    void on_menu_file_save();
};



#endif //NOTEX_EDITOR_H
