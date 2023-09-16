#include "user_view.hpp"



UserView::UserView(UsersManager & users_manager, BooksManager &books_manager) :
    users_manager(users_manager), books_manager(books_manager) {

}

void UserView::list_available_books() 
{
    const std::map<std::string, Book*>& mp = books_manager.get_isbn_book();

    std::cout << "\nOur current book collection:\n";
    int idx = 0;
    for (const auto &pair : mp) {
        // As we call ToString: we don't need to worry about book data members future changes
        std::cout << "\t" << ++idx << " " << pair.second->to_string() << "\n";
    }

    std::cout << "\nWhich book to read?: ";
    int choice = read_number(1, idx);	// For simplicity, assume a new book is selected

    idx = 0;
    for (const auto &pair : mp) {
        if (++idx == choice) {
            BookRead* session = users_manager.add_reaad_session(pair.second);
            display_session(session);
            break;
        }
    }

}
void UserView::list_read_history() 
{
    int idx = 0;
    const auto& sessions = users_manager.get_current_user()->get_read_session();
    for (auto& session : sessions) {
        std::cout << ++idx << ": " << session->to_string() << "\n";
    }

    if (idx == 0)
        std::cout << "\nNo history. List books and start having fun\n";
    else {
        std::cout << "\nWhich session to open?: ";
        int choice = read_number(1, idx);
        display_session(sessions[choice - 1]);
    }
}

void UserView::view_profile() 
{
    User* user = users_manager.get_current_user();

    std::cout << "\n" << user->to_string() << "\n";
}

void UserView::display() 
{
    User* user = users_manager.get_current_user();
    std::cout << "\n\nHello " << user->get_name() << " | User View\n";

    std::vector<std::string> menu;
    menu.push_back("View Profile");
    menu.push_back("List & Select from My Reading History");
    menu.push_back("List & Select from Available Books");
    menu.push_back("Logout");

    while (true) {
        int choice = show_read_menu(menu);
        if (choice == 1)
            view_profile();
        else if (choice == 2)
            list_read_history();
        else if (choice == 3)
            list_available_books();
        else
            break;
    }
}



void UserView::display_session(BookRead* session) 
{
    std::vector<std::string> menu;
    menu.push_back("Next Page");
    menu.push_back("Previous Page");
    menu.push_back("Stop Reading");

    while (true) {
        std::cout << "Current Page: " << session->page_idx_str() << "\n";
        std::cout << session->get_current_pagecontent() << "\n";

        int choice = show_read_menu(menu);
        if (choice == 1)
            session->next_page();
        else if (choice == 2)
            session->previous_page();
        else
            break;
    }
    session->reset_last_access_date();
}

