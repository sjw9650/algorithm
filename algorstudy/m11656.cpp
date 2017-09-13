#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<string> result;
	string inputstring;

	cin >> inputstring;
	int len = inputstring.length();

	for (int i = 0; i < len; i++) {
		result.push_back(inputstring.substr(i, len));
	}

	sort(result.begin(), result.end());
	
	for (vector<string>::iterator vi = result.begin(); vi != result.end(); vi++) {
		cout << *vi << "\n";
	}
}