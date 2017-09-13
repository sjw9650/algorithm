#include <iostream>
#include <stack>
#include <string>
int main() {
	int n;
	std::cin >> n;
	std::string temp;
	std::stack<int> st;
	for (int i = 0; i < n; i++) {
		std::cin >> temp;

		if (temp=="push") {
			int k;
			std::cin >> k;
			st.push(k);
		}
		else if(temp=="pop"){
			if (st.empty()) {
				std::cout << "-1\n";
			}
			else {

				int k = st.top();
				st.pop();
				std::cout << k<< "\n";
			}
		}
		else if (temp=="size") {
			std::cout << st.size() << "\n";
		}
		else if (temp =="empty") {
			if (st.empty()) 
				std::cout << "1\n";			
			else std::cout << "0\n";
		}
		else
		{
			if (st.empty()) {
				std::cout << "-1\n";
			}
			else {
				int k = st.top();
				std::cout << k << "\n";
			}
		
		}
	}
}