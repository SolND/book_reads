#ifndef _ONLINE_READ_SYSTEM_HPP
#define _ONLINE_READ_SYSTEM_HPP
#include "user_manager.hpp"
#include "book_manager.hpp"
#include "misc.hpp"
#include "user_view.hpp"
#include "admin_view.hpp"
class OnlineReaderSystem {
private:
	BooksManager *books_manager;
	UsersManager *users_manager;

	void load_database();

public:
    OnlineReaderSystem();
    ~OnlineReaderSystem();
    void run();
};
#endif