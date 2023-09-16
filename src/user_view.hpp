#ifndef _USER_VIEW_HPP
#define _USER_VIEW_HPP

#include "user_manager.hpp"
#include "book_manager.hpp"
class UserView 
{
public:

	UserView(UsersManager & users_manager, BooksManager &books_manager);
    void display();
    void view_profile();
    void display_session(BookRead* session);
    void list_read_history();
    void list_available_books();
private:
	UsersManager &users_manager;
	BooksManager &books_manager;
};
#endif