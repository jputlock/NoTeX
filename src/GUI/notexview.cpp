
#include "notexview.h"

NotexView::NotexView() : Gtk::ScrolledWindow() {
    this->set_hexpand(false);
    this->set_vexpand(true);
    this->set_size_request(200,200);
    this->show();

    this->m_textview.set_editable(true);
    this->m_textview.set_cursor_visible(true);
    this->m_textview.show();

    this->m_textview.set_size_request (200, 200);
    this->m_textview.set_wrap_mode(Gtk::WRAP_WORD);
    auto m_textBuffer = Gtk::TextBuffer::create();
    m_textBuffer->set_text("Welcome to NoTeX!");
    this->m_textview.set_buffer(m_textBuffer);

    this->add(m_textview);
}

NotexView::~NotexView() { }

void NotexView::set_text(const std::string& text) {
    this->m_textview.get_buffer()->set_text(text);
}

const std::string NotexView::get_text() {
    return this->m_textview.get_buffer()->get_text();
}
