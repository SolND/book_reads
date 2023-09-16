#ifndef _USER_VIEW_HPP
#define _USER_VIEW_HPP

#include "user_manager.hpp"
#include "book_manager.hpp"
#include "user.hpp"
class UserView 
{
public:

	UserView(UsersManager & users_manager, BooksManager &books_manager);
    void display();
    void view_profile();
    void display_session(BookRead* session);
    void list_read_history();
    void list_available_books();
    BooksManager &get_books_manager();
    void borrow_book();
    void return_book();

private:
	UsersManager &users_manager;
	BooksManager &books_manager;
};
#endif