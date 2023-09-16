#include "book_manager.hpp"

void BooksManager::load_database() {
    std::cout << "BooksManager: LoadDatabase\n";
    free_loaded_data();

    Book* book1 = new Book();
    book1->set_isbn("00001");
    book1->set_author("Rishu");
    book1->set_title("CPP By Rema Thareja");
    std::vector<std::string> pages1 = { "A C++", "B C++", "C C++", "D C++", "E C++" };
    book1->set_pages(pages1);
    add_book(book1);

    Book* book2 = new Book();
    book2->set_isbn("00002");
    book2->set_author("Rajan");
    book2->set_title("Intro to Algorithm");
    std::vector<std::string> pages2 = { "A Algo", "B Algo", "C Algo", "D Algo", "E " };
    book2->set_pages(pages2);
    add_book(book2);

    Book* book3 = new Book();
    book3->set_isbn("00003");
    book3->set_author("Rishu");
    book3->set_title("Data Structures in C++");
    std::vector<std::string> pages3 = { "A Data", "B Data", "C Data", "D Data", "E Data" };
    book3->set_pages(pages3);
    add_book(book3);
}

// BooksManager::BooksManager(const BooksManager&) = delete;
// void BooksManager::operator=(const BooksManager&) = delete;

BooksManager::~BooksManager() {
    std::cout << "Destuctor: BooksManager\n";
    free_loaded_data();
}

// CRUD operations
void BooksManager::add_book(Book* book) {
    isbn_to_book[book->get_isbn()] = book;
}

void BooksManager::update_book(std::string isbn, Book* book) {
}

void BooksManager::delete_book(std::string isbn) {
}

Book* get_book(std::string isbn) {
    return nullptr;
}

std::map<std::string, Book*>& BooksManager::get_isbn_book(){
    return this->isbn_to_book;
}

void BooksManager::set_isbn_book(const std::map<std::string, Book*>& isbnToBookMap) {
    this->isbn_to_book = isbnToBookMap;
}

void BooksManager::free_loaded_data() {
    for (auto pair : get_isbn_book()) {
        delete pair.second;
    }
    isbn_to_book.clear();
}