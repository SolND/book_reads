#include"book.hpp"

void Book::set_author(const std::string &author)
{
    this->author = author;
}

void Book::set_isbn(const std::string &isbn)
{
    this->isbn = isbn;
}

void Book::set_pages(const std::vector<std::string> &pages)
{
    this->pages = pages;
}

void Book::set_title(const std::string &title)
{
    this->title = title;
}

std::string Book::get_author()
{
    return this->author;
}

std::string Book::get_title()
{
    return this->title;
}

std::string Book::get_isbn()
{
    return this->isbn;
}

std::vector<std::string> &Book::get_pages()
{
    return this->pages;
}

void Book::read()
{
	std::string isbn;
	std::string title;
	std::string name;
	std::string str;
	int pages_count;

	std::cout << "Enter International Standard Book Number: ";
	std::cin >> isbn;
	set_isbn(isbn);
	std::cin.clear();
	std::cin.ignore(256, '\n');
	
	std::cout << "Enter Title: ";
	std::cin >> title;
	set_title(title);
	std::cin.clear();
	std::cin.ignore(256, '\n');

	std::cout << "Enter Author Name: ";
	std::cin >> name;
	set_author(name);
	std::cin.clear();
	std::cin.ignore(256, '\n');
	std::cout << "Enter How many pages: ";

	std::cin >> pages_count;

	for (int page = 0; page < pages_count; ++page) 
    {
		std::cout << "Enter page [" << page + 1 << "]: ";
		std::cin >> str;
		pages.push_back(str);
	}
}
