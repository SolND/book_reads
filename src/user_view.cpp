#include "user_view.hpp"



UserView::UserView(UsersManager & users_manager, BooksManager &books_manager) :
    users_manager(users_manager), books_manager(books_manager) {

}
BooksManager &UserView::get_books_manager() 
{
    return books_manager;
}
void UserView::list_available_books() 
{
    const std::map<std::string, Book*>& mp = books_manager.get_isbn_book();

    std::cout << "\nOur current book collection:\n";
    int idx = 0;
    for (const auto &pair : mp) {
        std::cout << "\t" << ++idx << " " << pair.second->get_title() << "\n";
    }

    std::cout << "\nWhich book to read?: ";
    int choice = read_number(1, idx);

    idx = 0;
for (const auto &pair : mp) {
    if (++idx == choice) {
        if (pair.second != nullptr) {
            BookRead* session = users_manager.add_reaad_session(pair.second);
            display_session(session);
        } else {
            std::cout << "Invalid choice. Book not found.\n";
        }
        break;
    }
}

}
void UserView::list_read_history() 
{
    int idx = 0;
    const auto& sessions = users_manager.get_current_user()->get_read_session();
    for (auto& session : sessions) {
        std::cout << ++idx << ": " << session->print() << "\n";
    }

    if (idx == 0)
        std::cout << "\nNo history.\n";
    else {
        std::cout << "\nWhich session to open?: ";
        int choice = read_number(1, idx);
        display_session(sessions[choice - 1]);
    }
}

void UserView::view_profile() 
{
    User* user = users_manager.get_current_user();

    std::cout << "\n" << user->print() << "\n";
}

void UserView::display() 
{
    User* user = users_manager.get_current_user();
    std::cout << "\n\nHello " << user->get_name() << " | User View\n";

    std::vector<std::string> menu;
    menu.push_back("Xem hồ sơ"); 
    menu.push_back("Liệt kê và chọn từ lịch sử đọc của tôi"); 
    menu.push_back("Danh sách & Chọn từ Sách có sẵn"); 
    menu.push_back("Mượn cuốn sách");
    menu.push_back("Trả cuốn sách");
    menu.push_back("Đăng xuất");

    while (true) {
        int choice = show_read_menu(menu);
        if (choice == 1)
            view_profile();
        else if (choice == 2)
            list_read_history();
        else if (choice == 3)
            list_available_books();
        else if (choice == 4)
            borrow_book();
        else if (choice == 5)
            return_book();
        else
            break;
    }
}

void UserView::display_session(BookRead* session) 
{
    if (session == nullptr) {
        std::cout << "Invalid session. Cannot display.\n";
        return;
    }
    
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

void UserView::borrow_book() 
{
    User* user = users_manager.get_current_user();
    std::vector<Book*> available_books;

    // Lấy danh sách sách có thể mượn
    for (const auto& pair : books_manager.get_isbn_book()) {
    Book* book = pair.second;
    if (std::find(user->get_borrowed_books().begin(), user->get_borrowed_books().end(), book) == user->get_borrowed_books().end()) {
        available_books.push_back(book);
    }
}

    if (available_books.empty()) {
        std::cout << "Không có sách khả dụng để mượn." << std::endl;
        return;
    }

    std::cout << "Chọn sách để mượn:" << std::endl;
    for (size_t i = 0; i < available_books.size(); ++i) {
        std::cout << i + 1 << ". " << available_books[i]->get_title() << std::endl;
    }

    int choice = read_number(1, available_books.size());

    // Mượn sách
    Book* selected_book = available_books[choice - 1];
    user->borrow_book(selected_book);
    std::cout << "Bạn đã mượn sách: " << selected_book->get_title() << std::endl;
}

void UserView::return_book() {
    User* user = users_manager.get_current_user();
    const std::vector<Book*>& borrowed_books = user->get_borrowed_books();

    if (borrowed_books.empty()) {
        std::cout << "Bạn không mượn cuốn sách nào." << std::endl;
        return;
    }

    std::cout << "Chọn sách để trả:" << std::endl;
    for (size_t i = 0; i < borrowed_books.size(); ++i) {
        std::cout << i + 1 << ". " << borrowed_books[i]->get_title() << std::endl;
    }

    int choice = read_number(1, borrowed_books.size());

    // Trả sách
    Book* selected_book = borrowed_books[choice - 1];
    user->return_book(selected_book);
    std::cout << "Bạn đã trả sách: " << selected_book->get_title() << std::endl;
}