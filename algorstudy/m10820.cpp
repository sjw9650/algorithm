#include <iostream>
#include <string>
using namespace std;

int main() {
	
	string temp;
	while (getline(cin, temp)) {
		int index[4] = { 0 };
		int len = temp.length();
		for (int i = 0; i < len; i++) {
			char temp2 = temp.at(i);
			if (temp2 == ' ') index[3]++;
			else if (temp2 >= 'A' && temp2 <= 'Z') 	index[1]++;
			else if (temp2 >= 'a' && temp2 <= 'z')	index[0]++;
			else index[2]++;
		}
		for (int i = 0; i < 4; i++)
			cout << index[i] << " ";
		cout << "\n";
	}
	system("pause");
}
