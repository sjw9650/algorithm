#include<iostream>
#include<string>
#include<stack>
int main() {
	int n;
	std::string std_;
	
	std::cin >> std_ >> n;

	std::stack<char> left_c;
	for (int i = 0; i < std_.length(); i++) {
		left_c.push(std_.at(i));
	}

	std::stack<char> right_c;

	char input_;
	char temp;
	for (int i = 0; i < n; i++) {
		std::cin >> input_;
		if (input_ == 'P') {
			std::cin >> temp;
			left_c.push(temp);
		}else if (input_ == 'L' && !left_c.empty()) {
			temp = left_c.top();
			left_c.pop();
			right_c.push(temp);
		}else if (input_ == 'D'&& !right_c.empty()) {
			temp = right_c.top();
			right_c.pop();
			left_c.push(temp);
		}else if(input_ == 'B'&& !left_c.empty())	{
			left_c.pop();
		}
	}
	int size_ = left_c.size();
	for (int i = 0; i < size_; i++) {
		temp = left_c.top();
		left_c.pop();
		right_c.push(temp);
	}
	while (!right_c.empty()) {
		temp = right_c.top();
		right_c.pop();
		std::cout << temp;
	}
}