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
    menu.push_back("Update Book");
    menu.push_back("Show book");
    menu.push_back("Delete Book");
    menu.push_back("Logout");

    while (true) {
        int choice = show_read_menu(menu);
        if (choice == 1)
            view_profile();
        else if (choice == 2)
            add_book();
        else if(choice == 3)
            update_book();
        else if(choice == 4)
            show_book();
        else if(choice == 5)
            delete_book();
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

    std::cout << "\n" << user->print() << "\n";
}

void AdminView::add_book() 
{
    Book *book = new Book();
    book->read();
    books_manager.add_book(book);
}

void AdminView::update_book() 
{
    std::string isbn;
    std::cout << "Nhập ISBN của sách bạn muốn cập nhật: ";
    std::cin >> isbn;
    if (books_manager.get_book(isbn) != nullptr) 
    {
        Book* updated_book = new Book();
        updated_book->read(); 

        books_manager.update_book(isbn, updated_book);

        std::cout << "Book with ISBN " << isbn << " has been updated.\n";
    } else {
        std::cout << "Book with ISBN " << isbn << " does not exist.\n";
    }
}

void AdminView::delete_book()
{
    std::string isbn;
    std::cout << "Nhập ISBN của sách bạn muốn xóa: ";
    std::cin >> isbn;

    if (books_manager.get_book(isbn) != nullptr) 
    {
        books_manager.delete_book(isbn);

        std::cout << "Sách có ISBN " << isbn << " đã bị xóa.\n";
    } 
    else {
        std::cout << "Sách có ISBN " << isbn << " không tồn tại.\n";
    }
}

void AdminView::show_book() 
{
    std::string isbn;
    std::cout << "Enter ISBN of the book you want to view: ";
    std::cin >> isbn;

    Book* book = books_manager.get_book(isbn);

    if (book != nullptr) 
    {
        std::cout << "Book Information:\n";
        std::cout << "ISBN: " << book->get_isbn() << "\n";
        std::cout << "Title: " << book->get_title() << "\n";
        std::cout << "Author: " << book->get_author() << "\n";

        std::cout << "Pages:\n";
        const std::vector<std::string>& pages = book->get_pages();
        for (size_t i = 0; i < pages.size(); ++i) {
            std::cout << i + 1 << ". " << pages[i] << "\n";
        }
    } 
    else {
        std::cout << "Book with ISBN " << isbn << " does not exist.\n";
    }
}
