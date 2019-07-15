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

    this->m_textview.set_size_request (200, 400);

    auto m_textBuffer = Gtk::TextBuffer::create();
    m_textBuffer->set_text("Welcome to NoTeX!");

    this->m_textview.set_buffer(m_textBuffer);

    // Add everything to the box
    this->m_box.add(this->m_textview);
    this->m_box.add(this->m_button);

    // The final step is to display this newly created widget...
    this->m_button.show();
    this->m_textview.show();

    // Add a container to hold everything
    this->add(this->m_img);
    // this->add(this->m_box);

    this->m_img.show();
    // this->m_box.show();

    // When the button receives the "clicked" signal, it will call the
    // on_button_clicked() method defined below.
    this->m_button.signal_clicked().connect(sigc::mem_fun(*this,
                                                    &Editor::on_button_clicked));

}

Editor::~Editor() {}

void Editor::on_button_clicked() {
    std::cout << "Save button clicked!";
    // todo: save functionality
}
