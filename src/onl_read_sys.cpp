#include "onl_read_sys.hpp"

void OnlineReaderSystem::load_database() 
{
    users_manager->load_database();
    books_manager->load_database();
}
OnlineReaderSystem::OnlineReaderSystem() : books_manager(new BooksManager()), users_manager(new UsersManager()) 
{

}

OnlineReaderSystem::~OnlineReaderSystem() 
{
    std::cout << "Destuctor: OnlineReaderSystem\n";

    if (books_manager != nullptr) {
        delete books_manager;
        books_manager = nullptr;
    }
    if (users_manager != nullptr) {
        delete users_manager;
        users_manager = nullptr;
    }
}

void OnlineReaderSystem::run() 
{	
    load_database();

    while (true) {
        users_manager->access_system();	// login/signup

        if (users_manager->get_current_user()->get_is_lib_admin()) 
        {
            AdminView view(*users_manager, *books_manager);
            view.display();
        } else {
            UserView view(*users_manager, *books_manager);
            view.display();
        }
    }
}