#include<iostream>
using namespace std;

int main() {

	int n;
	cin >> n;
	long long *Arr = new long long[n + 1];
	Arr[3] = 1;
	if (n >= 4) { Arr[4] = -1; if (n >= 5) Arr[5] = 1; }
	for (int i = 6;i<n+1;i++)
	{
		if (i % 5 == 0) Arr[i] = i / 5;
		else if (Arr[i - 3] != -1) Arr[i] = Arr[i - 3] + 1;
		else Arr[i] = -1;

	}

	cout << Arr[n];

	delete Arr;
	return 0;
}