#include <iostream>
#include <string>
using namespace std;



int main() {
	int alphabet[26];
	for (int i = 0; i < 26; i++)
		alphabet[i] = -1;
	string ind;
	cin >> ind;
	for (int i = 0; i < ind.length(); i++)
	{
		if(alphabet[ind.at(i) - 'a']==-1)
			alphabet[ind.at(i) - 'a'] = i;
	}
	for (int i = 0; i < 26; i++)
		cout << alphabet[i] << " ";
	cout << "\n";
	return 0;
}