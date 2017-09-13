#include <iostream>
#include <stack>
#include <string>
int main() {
	std::string data_;
	std::cin >> data_;
	int size_ = data_.length();
	int flags_ = 0;
	long long result = 0;
	std::stack<char> st_;
	for (int i = 0; i < size_; i++) {
		if (data_.at(i) == '(') {
			st_.push('(');
			flags_ = 1;
		}
		else {
			st_.pop();
			if (flags_ == 1) {
				
				result+=st_.size();
			}
			else {
				result++;
			}
			flags_ = 0;
			
		}
	}
	std::cout << result;
}