#ifndef _USER_MANAGER_HPP
#define _USER_MANAGER_HPP
#include "user.hpp"
#include "book_read.hpp"
#include "book_manager.hpp"
class UsersManager 
{
private:
	User* current_user = nullptr;
	std::map<std::string, User*> userame_userobject;
    // BooksManager &books_manager;
    void free_loaded_data();

public:
    UsersManager();
    // UsersManager(BooksManager &books_manager);
	~UsersManager();
    UsersManager(const UsersManager&) = delete;
	void operator=(const UsersManager&) = delete;
    BookRead* add_reaad_session(Book* book);
    void sign_up();
    void access_system();
    void login();
    void load_database();
    User* get_current_user();
    void set_current_user(User* ptr);

};
#endif