#include<iostream>
#include<string>
using namespace std;
int main() {
	string input;
	string arr = "";
	getline(cin, input);
	for (int i = 0; i<input.length(); i++)
	{
		string temp = input.substr(i, 1);
		if (temp == "a" || temp == "i" || temp == "e" || temp == "o" || temp == "u")
			i += 2;
		arr += temp;
	}
	cout << arr;
}
