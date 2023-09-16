#ifndef _BOOK_HPP
#define _BOOK_HPP
#include <iostream>
#include <string>
#include <vector>
#include "misc.hpp"
class Book
{
public:
    Book(){};
    ~Book(){};
    void read();
    void set_author(const std::string &author);
    void set_isbn(const std::string &isbn);
    void set_pages(const std::vector<std::string> &pages);
    void set_title(const std::string &title);

    std::string get_author();
    std::string get_title();
    std::string get_isbn();
    std::vector<std::string> &get_pages();

private:
    std::string title;
    std::string isbn; //International Standard Book Number
    std::string author;
    std::vector<std::string> pages;
};


#endif