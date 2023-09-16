#include"user_manager.hpp"

UsersManager::UsersManager() 
{
}

UsersManager::~UsersManager() {
    std::cout << "Destuctor: UsersManager\n";
    free_loaded_data();
}

void UsersManager::load_database() {
    std::cout << "UsersManager: LoadDatabase\n";

    free_loaded_data();
    // Some "Dummy Data" for simplicity
    User* user1 = new User();
    user1->set_user_name("Rishu");
    user1->set_password("82");
    user1->set_mail("rishurajan57@gmail.com");
    user1->set_library_admin(true);
    user1->set_name("Rishu Rajan");
    userame_userobject[user1->get_user_name()] = user1;

    User* user2 = new User();
    user2->set_user_name("Rajan");
    user2->set_password("1999");
    user2->set_mail("rajan@gmail.com");
    user2->set_library_admin(false);
    user2->set_name("Titu Kumar");
    userame_userobject[user2->get_user_name()] = user2;
}

void UsersManager::access_system() {
    int choice = show_read_menu( { "Login", "Sign Up" });
    if (choice == 1)
        login();
    else
        sign_up();
}

void UsersManager::login() {
    load_database();

    while (true) {
        std::string user_name= "", pass = "";
        std::cin.clear();
        //std::cin.ignore(256, '\n');
        std::cout << "Enter user_name: ";
        std::cin >> user_name;

        std::cin.clear();
        std::cout << "Enter password: ";
        std::cin >> pass;
        if (!userame_userobject.count(user_name)) {
            std::cout << "\nInvalid user user_name or password. Try again\n\n";
            continue;
        }
        User* user_exist = userame_userobject.find(user_name)->second;

        if (pass != user_exist->get_password()) {
            std::cout << "\nInvalid user user_name or password. Try again\n\n";
            continue;
        }
        current_user = user_exist;
        break;
    }
}

void UsersManager::sign_up() {
    std::string user_name;
    while (true) {
        std::cout << "Enter user name. (No spaces): ";
        std::cin.clear();
        std::cin >> user_name;

        if (userame_userobject.count(user_name))
            std::cout << "Already used. Try again\n";
        else
            break;
    }

    current_user->read(user_name);
    userame_userobject[current_user->get_user_name()] = current_user;
}

BookRead* UsersManager::add_reaad_session(Book* book) {
    return current_user->add_reaad_session(book);
}

User* UsersManager::get_current_user()
{
    return current_user;
}
void UsersManager::free_loaded_data() 
{
    for (auto pair : userame_userobject) {
        delete pair.second;
    }
    userame_userobject.clear();
    set_current_user(nullptr);
}
void UsersManager::set_current_user(User* ptr)
{
    this->current_user = ptr;
}