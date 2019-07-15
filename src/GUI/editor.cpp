//
// Created by jputlock on 6/1/19.
//

#include "editor.h"
#include <iostream>

Editor::Editor() : m_textview(), m_button("Save file"), m_img("new.svg") {

    // Set title and border width
    this->set_title("NoTeX");
    this->set_border_width(5);

    // Allow ClickableImages to receive input
    this->set_events(Gdk::BUTTON_PRESS_MASK);

    // Set up the textview
    this->m_textview.set_size_request (200, 400);
    auto m_textBuffer = Gtk::TextBuffer::create();
    m_textBuffer->set_text("Welcome to NoTeX!");
    this->m_textview.set_buffer(m_textBuffer);

    // Set up the menubar
    this->m_menuFile.set_label("File");
    this->m_menuBar.append(this->m_menuFile);

    // Set up file submenu
    this->m_menuFile.set_submenu(this->m_subMenuFiles);
    this->m_menuNew.set_label("New");
    this->m_menuOpen.set_label("Open");
    this->m_menuSave.set_label("Save");
    this->m_subMenuFiles.append(this->m_menuNew);
    this->m_subMenuFiles.append(this->m_menuOpen);
    this->m_subMenuFiles.append(this->m_menuSave);

    // Add everything to the box
    this->m_fixed.put(this->m_menuBar, 0, 0);
    this->m_fixed.put(this->m_textview, 0, 30);
    this->m_fixed.put(this->m_img, 200, 200);

    // Add a container to hold everything
    this->add(this->m_fixed);

    this->show_all_children();
}

Editor::~Editor() {}
