#include"user_manager.hpp"

UsersManager::UsersManager() 
{
    current_user = nullptr;
}

UsersManager::~UsersManager() {
    std::cout << "Destuctor: UsersManager\n";
    free_loaded_data();
    if (current_user) 
    {
        delete current_user;
        current_user = nullptr;
    }
}

void UsersManager::load_database() {
    std::cout << "UsersManager: LoadDatabase\n";

    free_loaded_data();
    // Some "Dummy Data" for simplicity
    User* user1 = new User();
    user1->set_user_name("Zohar");
    user1->set_password("82");
    user1->set_mail("sond1909@gmail.com");
    user1->set_library_admin(true);
    user1->set_name("Son");
    userame_userobject[user1->get_user_name()] = user1;
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
        std::cout << "Điền tên đăng nhập: ";
        std::cin >> user_name;

        std::cin.clear();
        std::cout << "Nhập mật khẩu: ";
        std::cin >> pass;
        if (!userame_userobject.count(user_name)) {
            std::cout << "\nTên người dùng hoặc mật khẩu người dùng không hợp lệ. Thử lại\n\n";
            continue;
        }
        User* user_exist = userame_userobject.find(user_name)->second;

        if (pass != user_exist->get_password()) {
            std::cout << "\nTên người dùng hoặc mật khẩu người dùng không hợp lệ. Thử lại\n\n";
            continue;
        }
        current_user = user_exist;
        break;
    }
}

void UsersManager::sign_up() 
{
    std::string user_name;
    while (true) {
        std::cout << "Điền tên đăng nhập. (No spaces): ";
        std::cin >> user_name;
        
        if (userame_userobject.count(user_name))
            std::cout << "Already used. Try again\n";
        else
            break;
    }
    current_user = new User(); // Khởi tạo một đối tượng User mới
    get_current_user()->read(user_name);
    userame_userobject[get_current_user()->get_user_name()] = current_user;

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