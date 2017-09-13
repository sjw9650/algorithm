
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	string t;
	getline(cin,t);
	T = atoi(t.c_str());
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		string data_string="";
		getline(cin, data_string);
		int length_string = data_string.length();

		vector<char> stack_;

		int temp_max = 0;
		int temp_parent = 0;
		int temp_num = 0;

		for (int i = 0; i < length_string; i++) {
			if (data_string[i] == ')' || data_string[i] == '}' || data_string[i] == ']')  {
				if(stack_.size() > 0){
					char temp_ch = stack_.back();
					stack_.pop_back();
					if ((temp_ch == '('&&data_string[i] == ')') || (temp_ch == '{'&&data_string[i] == '}') || (temp_ch == '['&&data_string[i] == ']'))
					{
						temp_max += 2;
					}
					else {
						stack_.clear();
						temp_max = 0;
					}
				}
				else {
					temp_max = 0;
				}
			}
			else {
				stack_.push_back(data_string[i]);
			}
			if(stack_.empty())
				Answer = max(Answer, temp_max);
		}

		std::cout << "Case #" << test_case + 1 << endl;
		std::cout << Answer << endl;
	}
	return 0;//Your program should return 0 on normal termination.
}