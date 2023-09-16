#include "book_read.hpp"

BookRead::BookRead() //: BookRead(nullptr) 
{
    BookRead(nullptr);
}

BookRead::BookRead(Book* books) : book(book), current_page(0), last_access_date(get_current_time_date())
{
    // this->book = books;
    // this->current_page = 0;
    // this->last_access_date = get_current_time_date();
}

void BookRead::set_current_page(int page)
{
    this->current_page = page;
}
void BookRead::set_last_access_date(std::string date)
{
    this->last_access_date = date;
}
void BookRead::set_book(Book * book)
{
    this->book = book;
}
std::string BookRead::get_current_pagecontent() {
    return book->get_pages()[current_page];
}

Book* BookRead::get_book(){
    return this->book;	// No set
}

std::string &BookRead::get_last_access_date(){
    return this->last_access_date;
}

void BookRead::reset_last_access_date() {	// More convenient
    set_last_access_date(get_current_time_date());
}

int BookRead::get_current_page()
{
    return this->current_page;
}

std::string BookRead::page_idx_str() 
{
    std::ostringstream oss;
    oss << get_current_page() + 1 << "/" << book->get_pages().size();
    return oss.str();
}

void BookRead::next_page() 
{   
    if (get_current_page() < (int) book->get_pages().size() - 1)
    {
        int n = 0;

    }
}
void BookRead::previous_page() 
{
    if (current_page > 0)
        current_page--;
}
std::string BookRead::to_string() 
{
    std::ostringstream oss;
    oss << get_book()->get_title() << " Page: " << page_idx_str() << " - " << get_last_access_date();
    return oss.str();
}