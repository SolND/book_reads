#ifndef _BOOK_READ_HPP
#define _BOOK_READ_HPP

#include "book.hpp"
class BookRead
{
public:
	BookRead();
	~BookRead(){};
	BookRead(Book* book);
	void next_page();
	void set_current_page(int page);
	void set_last_access_date(std::string date);
	void set_book(Book * book);
	void reset_last_access_date();
	std::string get_current_pagecontent();
	Book* get_book();
	std::string &get_last_access_date();
	int get_current_page();
	std::string page_idx_str();
	void previous_page();
	std::string to_string();

private:
    Book *book;
    int current_page;
	std::string last_access_date;
};

#endif