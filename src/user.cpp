#include "user.hpp"


User::User()
{
    this->is_library_admin = false;
    this->user_name = "";
    this->password = "";
    this->name = "";
    this->email = "";
}
User::~User() 
{
    std::cout << "Destructor User\n";
    for (auto &session : reading_sessions)
        delete session;

    reading_sessions.clear();
}

void User::set_mail(const std::string &mail)
{
    this->email = mail;
}
void User::set_password(const std::string &pass)
{
    this->password = pass;
}
void User::set_user_name(const std::string &user)
{
    user_name = user;
}
void User::set_name(const std::string &name)
{
    this->name = name;
}
bool User::set_library_admin(bool admin)
{
    this->is_library_admin = admin;
}
std::vector<BookRead*> User::get_read_session()
{
    return this->reading_sessions;
}
std::string User::get_password()
{
    return this->password;
}
std::string User::get_user_name()
{
    return this->user_name;
}
std::string User::get_name()
{
    return this->name;
}
bool User::get_is_lib_admin()
{
    return this->is_library_admin;
}
BookRead* User::add_reaad_session(Book* book)
{
    BookRead* session = new BookRead(book);
	reading_sessions.push_back(session);
	return session;
}
void User::read(const std::string &user_name) 
{
	set_user_name(user_name);
    std::cin.clear();
	std::cin.ignore(256, '\n');

	std::string pass;
    std::string name;
    std::string mail;

	std::cout << "Enter password: ";
	std::cin >> pass;
	set_password(pass);
	std::cin.clear();
	std::cin.ignore(256, '\n');

	std::cout << "Enter name: ";
	std::cin >> name;
	set_name(name);
	std::cin.clear();
	std::cin.ignore(256, '\n');

	std::cout << "Enter email: ";
	std::cin >> mail;
	set_mail(mail);
    std::cin.clear();
	std::cin.ignore(256, '\n');
}

std::string User::print()
{
    std::ostringstream oss;
    oss << "Name: " << get_user_name();
    if (get_is_lib_admin())
        oss << " | Admin";
    oss << "\n";
    oss << "Email: " << email << "\n";
    oss << "User name: " << user_name << "\n";
    return oss.str();
}

void User::borrow_book(Book* book) 
{
    borrowed_books.push_back(book);
}

void User::return_book(Book* book) 
{
    // Tìm và xóa sách đã trả khỏi danh sách mượn
    auto it = std::find(borrowed_books.begin(), borrowed_books.end(), book);
    if (it != borrowed_books.end()) 
    {
        borrowed_books.erase(it);
    }
}

const std::vector<Book*>& User::get_borrowed_books() const {
    return borrowed_books;
}