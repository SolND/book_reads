#ifndef _BOOK_MANAGER_HPP
#define _BOOK_MANAGER_HPP
#include "book.hpp"
#include "user_manager.hpp"

class BooksManager
{
public:
	BooksManager() {}
	~BooksManager();
	void load_database();
	BooksManager(const BooksManager&) = delete;
	void operator=(const BooksManager&) = delete;

	// CRUD operations
	void add_book(Book* book);
	void update_book(std::string isbn, Book* book);
	void delete_book(std::string isbn);
	Book* get_book(std::string isbn);
	std::map<std::string, Book*>& get_isbn_book();
	void set_isbn_book(const std::map<std::string, Book*>& isbnToBookMap);
private:
	std::map<std::string, Book*> isbn_to_book;

	void free_loaded_data();
};

#endif