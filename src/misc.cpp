#include "misc.hpp"
 int read_number(int low, int high) {
	std::cout << "\nEnter number in range " << low << " - " << high << ": ";
	int value;

	std::cin >> value;

	if (low <= value && value <= high)
		return value;

	std::cout << "ERROR: invalid number...Try again\n";
	return read_number(low, high);
}

 int show_read_menu(std::vector<std::string> choices) {
	std::cout << "\nMenu:\n";
	for (int ch = 0; ch < (int) choices.size(); ++ch) {
		std::cout << "\t" << ch + 1 << ": " << choices[ch] << "\n";
	}
	return read_number(1, choices.size());
}

std::string get_current_time_date() {	
	auto now = std::chrono::system_clock::now();
	auto in_time_t = std::chrono::system_clock::to_time_t(now);

	std::stringstream ss;
	ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
	return ss.str();
}