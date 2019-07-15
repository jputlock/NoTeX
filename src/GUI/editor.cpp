//
// Created by jputlock on 6/1/19.
//

#include <iostream>

#include "editor.h"
#include "../debug.h"

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

    this->initialize_menubar();

    // Add everything to the box
    this->m_fixed.put(this->m_menuBar, 0, 0);
    this->m_fixed.put(this->m_textview, 0, 30);
    this->m_fixed.put(this->m_img, 200, 200);

    // Add a container to hold everything
    this->add(this->m_fixed);

    this->show_all_children();
}

Editor::~Editor() {}

void Editor::initialize_menubar() {

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

        // Connect submenu to functions
        this->m_menuNew.signal_activate().connect(sigc::mem_fun(*this, &Editor::on_menu_file_new));
        this->m_menuOpen.signal_activate().connect(sigc::mem_fun(*this, &Editor::on_menu_file_open));
        this->m_menuSave.signal_activate().connect(sigc::mem_fun(*this, &Editor::on_menu_file_save));
#ifdef DEBUG
        debug_print("Menubar finished initializing");
#endif
        // code here
}

void Editor::on_menu_file_new() {
    std::cout << "Selected new file" << std::endl;
}

void Editor::on_menu_file_open() {
    std::cout << "Selected open file" << std::endl;
}

void Editor::on_menu_file_save() {
    std::cout << "Selected save file" << std::endl;
}
