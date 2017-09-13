#include <iostream>
#include <queue>
#include <string>

int main() {
	int n; 
	std::ios::sync_with_stdio(false);
	std::queue<int> result;
	std::cin >> n;
	std::string temp;
	int temp_int;
	for (int i = 0; i < n; i++) {
		std::cin >> temp;
		if (temp == "push") {
			std::cin >> temp_int;
			result.push(temp_int);
		}
		else if (temp == "pop") {
			if (result.empty()) {
				std::cout << "-1\n";
			}
			else {
				temp_int = result.front();
				result.pop();
				std::cout << temp_int << "\n";
			}
		}
		else if (temp == "size") std::cout << result.size()<<"\n";
		else if (temp == "empty")
			if (result.empty()) std::cout << "1\n";
			else std::cout << "0\n";
		else if (temp == "front")
			if (result.empty()) std::cout << "-1\n";
			else std::cout << result.front() << "\n";
		else if (temp == "back")
			if (result.empty()) std::cout << "-1\n";
			else std::cout << result.back() << "\n";
	}
}