#include<iostream>
#include<list>
using namespace std;
int main() {
	int n;
	cin >> n;
	list<int> arr;
	for (int i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	arr.sort();
	list<int>::iterator li;
	for (li = arr.begin(); li != arr.end(); li++)
		cout << *li << endl;
	system("pause");
}
