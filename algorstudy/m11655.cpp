#include<iostream>
#include<string>
#include<queue>
using namespace std;

int main() {

	string temp;
	getline(cin, temp);

	int len = temp.length();

	for (int i = 0; i < len; i++) {
		char temp2 = temp.at(i);
		char temp3 = ' ';
		if (temp2 <= 'Z'&&temp2 >= 'A') {
			if (temp2 + 13 > 'Z')
				temp3 = 'A' + temp2 + 12 - 'Z';
			else 
				temp3 = temp2 + 13;
		}
		else if (temp2 <= 'z' && temp2 >= 'a') {
			if (temp2 + 13 > 'z')
				temp3 = 'a' + temp2 + 12 - 'z';
			else
				temp3 = temp2 + 13;
		}
		else temp3 = temp2;

		cout << temp3;

	}
	cout << "\n";

}