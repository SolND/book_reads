#ifndef _ADMIN_VIEW_HPP
#define _ADMIN_VIEW_HPP

#include "user_manager.hpp"
#include "book_manager.hpp"
// #include ""
class AdminView 
{
public:
    // AdminView();
    ~AdminView();
    AdminView(UsersManager &users_manager, BooksManager &books_manager);
    void display();
    void view_profile();
    void add_book();
    void delete_book();
    void update_book();
    void show_book();
    void set_users_manager(UsersManager &manager);
    void set_book_manager(BooksManager &manager);
private:
	UsersManager &users_manager;
	BooksManager &books_manager;
};
#endif