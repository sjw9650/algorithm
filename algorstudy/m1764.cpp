#include<iostream>
#include<string>
#include<set>
#include<list>
using namespace std;

int main() {
	int n, m;
	set<string> arr;
	int counts = 0;
	list<string> result;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		arr.insert(temp);
	}
	for (int i = 0; i < m; i++)
	{
		string temp;
		cin >> temp;
		set<string>::iterator si;
		si = arr.find(temp);
		if (si != arr.end()) {
			counts++;
			result.push_back(temp);
		}
	}
	result.sort();
	cout << counts << endl;

	list<string>::iterator vi;
	for (vi = result.begin(); vi != result.end(); vi++) cout << *vi << endl;

}
