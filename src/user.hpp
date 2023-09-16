#ifndef _USER_HPP
#define _USER_HPP

#include "book_read.hpp"
class User 
{
public:

	// If you have pointers internally: start with canceling copy constructor, so that you discover any bugs due to misuse
	// Provide it based on logic & needs
	User(const User&) = delete;
	void operator=(const User&) = delete;
    User();
    ~User();
    BookRead* add_reaad_session(Book* book);
    void set_mail(const std::string &mail);
    void set_password(const std::string &pass);
    void set_user_name(const std::string &user_name);
    void set_name(const std::string &name);
    bool set_library_admin(bool admin);
    std::string _get_mail();
    std::string get_password();
    std::string get_user_name();
    std::string get_name();
    bool get_is_lib_admin();
    std::vector<BookRead*> get_read_session();
    std::string print();
    void read(const std::string &user_name);
    const std::vector<Book*>& get_borrowed_books() const;
    void borrow_book(Book* book);
    void return_book(Book* book);
private:
	std::string user_name;
	std::string password;
	std::string name;
	std::string email;
	bool is_library_admin;
    std::vector<Book*> borrowed_books;
	std::vector<BookRead*> reading_sessions;
};

#endif