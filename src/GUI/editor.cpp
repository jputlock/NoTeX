//
// Created by jputlock on 6/1/19.
//

#include <iostream>
#include <fstream>

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

/** @brief Creates a new text buffer to work on
 *
 */
void Editor::on_menu_file_new() {
    std::cout << "Selected new file" << std::endl;

    // todo: implement actual "new file" functionality
    // ideas: hold the name of the file we're working on
    // and swap it off at this point
    auto new_buffer = Gtk::TextBuffer::create();
    this->m_textview.set_buffer(new_buffer);
}

void Editor::on_menu_file_open() {
    std::cout << "Selected open file" << std::endl;

    Gtk::FileChooserDialog file_chooser("Select a file",
                                        Gtk::FILE_CHOOSER_ACTION_OPEN);
    file_chooser.set_transient_for(*this);

    // Add response buttons to dialog
    file_chooser.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    file_chooser.add_button("_Open", Gtk::RESPONSE_OK);

    // we can add filters here to only allow certain filetypes

    // actually run it and collect the result
    int result = file_chooser.run();


    switch(result) {
        case (Gtk::RESPONSE_OK): {
            std::cout << "Folder selected: " << file_chooser.get_filename()
                                             << std::endl;

            std::ifstream file_istream;
            file_istream.open(file_chooser.get_filename());

            auto text_buffer = Gtk::TextBuffer::create();

            // todo: check this section over... wrote it without access
            // to documentation
            char buffer[1000];
            std::string temp_text;
            Glib::ustring text_builder;

            while (!file_istream.eof()) {
                file_istream.read(buffer, 1000);
                temp_text = buffer;
                std::cout << temp_text << std::endl;
                text_builder += temp_text;
            }

            text_buffer->set_text(text_builder);
            m_textview.set_buffer(text_buffer);

            std::cout << "Opened from " << file_chooser.get_filename()
                                        << std::endl;

            file_istream.close();

            std::cout << "Closed filestream to " << file_chooser.get_filename()
                                                 << std::endl;

            break;
        }
        case (Gtk::RESPONSE_CANCEL): {
            std::cout << "Cancel clicked." << std::endl;
            break;
        }
        default: {
            std::cerr << "Unexpected action occurred in Editor::on_menu_file_open()"
                      << std::endl;
            break;
        }
    }
}

void Editor::on_menu_file_save() {
    std::cout << "Selected save file" << std::endl;

    Gtk::FileChooserDialog file_chooser("Select a file",
                                        Gtk::FILE_CHOOSER_ACTION_SELECT_FOLDER);
    file_chooser.set_transient_for(*this);

    // Add response buttons to dialog
    Gtk::Entry entry;
    // this number is arbitrary but it ok at 93?
    int entry_width = 93;
    entry.set_width_chars(entry_width);
    entry.set_max_width_chars(entry_width);
    entry.show();

    // all default response id's are in [-1, -11]
    file_chooser.add_action_widget(entry, 0);
    file_chooser.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    file_chooser.add_button("Select", Gtk::RESPONSE_OK);

    int result = file_chooser.run();

    // handle the result
    switch(result) {
        case (Gtk::RESPONSE_OK): {

            // construct the file location
            // todo: make this usable with windows filesystems
            std::string file_location = file_chooser.get_filename() + "/"
                                                            + entry.get_text();
            std::cout << "Location selected: " << file_location << std::endl;

            std::ofstream file_ostream;
            file_ostream.open(file_location);

            auto text_buffer = m_textview.get_buffer();

            file_ostream << text_buffer->get_text();

            std::cout << "Saved to " << file_location << std::endl;

            file_ostream.close();

            std::cout << "Closed filestream to " << file_location << std::endl;

            break;
        }
        case (Gtk::RESPONSE_CANCEL): {
            std::cout << "Cancel clicked." << std::endl;
            break;
        }
        default: {
            std::cerr << "Unexpected action occurred in Editor::on_menu_file_save()"
                      << std::endl;
            break;
        }
    }



}
