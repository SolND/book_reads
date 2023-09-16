#include"book.hpp"

void Book::read()
{
	std::string str;

	std::cout << "Enter International Standard Book Number: ";
	std::cin >> str;
	set_isbn(str);

	std::cout << "Enter Title: ";
	std::cin >> str;
	set_title(str);

	std::cout << "Enter Author Name: ";
	std::cin >> str;
		set_author(str);

	std::cout << "Enter How many pages: ";
	int pages_count;
	std::cin >> pages_count;

	for (int page = 0; page < pages_count; ++page) 
    {
		std::cout << "Enter page [" << page + 1 << "]: ";
		std::cin >> str;
		pages.push_back(str);
	}
}
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
std::string Book::to_string()
{
return title;
}