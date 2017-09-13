#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> arr;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
	}
	int sum=0;
	vector<int>::reverse_iterator vi;
	for (vi = arr.rbegin(); vi != arr.rend(); vi++)
	{
		int a = *vi;
		int b = k / a;
		k -= a*b;
		sum += b;
		if (k == 0) break;
	}
	cout << sum;
}