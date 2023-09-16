#include "admin_view.hpp"

// AdminView::AdminView()
// {

// }
AdminView::~AdminView()
{

}

AdminView::AdminView(UsersManager &users_manager, BooksManager &books_manager) : users_manager(users_manager), books_manager(books_manager)
{

}

void AdminView::display() 
{
    User* user = users_manager.get_current_user();

    std::cout << "\n\nHello " << user->get_name() << " | Admin View\n";
    std::vector<std::string> menu;
    menu.push_back("View Profile");
    menu.push_back("Add Book");
    menu.push_back("Logout");

    while (true) {
        int choice = show_read_menu(menu);
        if (choice == 1)
            view_profile();
        else if (choice == 2)
            add_book();
        else
            break;
    }
}

// void AdminView::set_users_manager(UsersManager manager)
// {
//     this->users_manager = manager;
// }

// void AdminView::set_book_manager(BooksManager manager)
// {
//     this->books_manager = manager;
// }
void AdminView::view_profile() {
    User* user = users_manager.get_current_user();

    std::cout << "\n" << user->to_string() << "\n";
}

void AdminView::add_book() 
{
    Book *book = new Book();
    book->read();
    books_manager.add_book(book);
}