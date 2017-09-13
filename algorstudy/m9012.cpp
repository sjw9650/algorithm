#include <iostream>
#include <stack>
#include <string>

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		int flags = 0;
		std::stack<int> temp_stack;
		std::string input_d;
		std::cin >> input_d;
		int size_ = input_d.size();
		for (int j = 0; j < size_; j++) {
			if (input_d.at(j) == '(') {
				temp_stack.push('(');
			}
			else if (temp_stack.empty()) {
				flags = 1;
				break;
			}
			else {
				temp_stack.pop();
			}
		}
		if (!temp_stack.empty()) {
			flags = 1;
		}

		if (flags == 1) std::cout << "NO\n";
		else std::cout << "YES\n";
	}
}