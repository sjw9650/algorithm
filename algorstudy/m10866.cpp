#include <iostream>
#include <deque>
#include <string>
int main() {
	int n;
	std::string temp;
	std::cin >> n;
	std::deque<int> data_dq;
	int intemp;
	for (int i = 0; i < n; i++) {
		std::cin >> temp;
		if (temp == "push_front") {
			std::cin >> intemp;
			data_dq.push_front(intemp);
		}
		else if (temp == "push_back") {

			std::cin >> intemp;
			data_dq.push_back(intemp);
		}
		else if (temp == "pop_front") {
			if (data_dq.empty()) {
				std::cout << "-1\n";
			}
			else {
				intemp = data_dq.front();
				data_dq.pop_front();
				std::cout << intemp << "\n";
			}
		}
		else if (temp == "pop_back") {
			if (data_dq.empty()) {
				std::cout << "-1\n";				
			}
			else {
				intemp = data_dq.back();
				data_dq.pop_back();
				std::cout << intemp << "\n";
			}
		}
		else if (temp == "size") {
			std::cout << data_dq.size() << "\n";
		}
		else if (temp == "empty") {
			if (data_dq.empty()) {
				std::cout << "1\n";
			}
			else {
				std::cout << "0\n";
			}
		}
		else if (temp == "front") {
			if (data_dq.empty()) {
				std::cout << "-1\n";
			}
			else {
				intemp = data_dq.front();
				std::cout << intemp << "\n";
			}
		}
		else if (temp == "back") {
			if (data_dq.empty()) {
				std::cout << "-1\n";
			}
			else {
				intemp = data_dq.back();
				std::cout << intemp << "\n";
			}
		}

	}
}