#ifndef _MISC_HPP
#define _MISC_HPP
#include <iostream>
#include <chrono>
#include <string>
#include <ctime>
#include <vector>
#include <sstream>
#include <iomanip>
#include <map>
#include <algorithm>

////////////////////////// Utilities //////////////////////////
int read_number(int low, int high);
int show_read_menu(std::vector<std::string> choices);
std::string get_current_time_date();
#endif