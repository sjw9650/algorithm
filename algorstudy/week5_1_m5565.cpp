#include <iostream>
using namespace std;

int main() {
	int money;
	cin >> money;
	for (int i = 0; i < 9; i++)
	{
		int temp;
		cin >> temp;
		money -= temp;
	}
	cout << money;
}