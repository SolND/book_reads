#ifndef _USER_MANAGER_HPP
#define _USER_MANAGER_HPP
#include "user.hpp"
#include "book_read.hpp"
class UsersManager {
private:
	User* current_user = nullptr;
	static std::map<std::string, User*> userame_userobject;

    void free_loaded_data();

public:
    UsersManager();
	~UsersManager();
    // UsersManager(const UsersManager&) = delete;
	// void operator=(const UsersManager&) = delete;
    BookRead* add_reaad_session(Book* book);
    void sign_up();
    void access_system();
    void login();
    void load_database();
    User* get_current_user();
    void set_current_user(User* ptr);

};
#endif