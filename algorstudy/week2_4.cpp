#include<iostream>
#include<algorithm>
#include<windows.h>

using namespace std;

int main(){
	int n;
	cin >> n;

	long long *arr = new long long[n];
	long long *maxarr = new long long[n];
	
	for (int i = 0; i < n; i++ )
		cin >> arr[i];

	maxarr[0] = arr[0];

	if (n >= 2)
	{
		maxarr[1] = maxarr[0] + arr[1];
		if (n >= 3)
		{
			maxarr[2] =max(maxarr[0]+arr[2],arr[1]+arr[2]);
		}
	}
	for (int i = 3; i < n; i++)
	{
		maxarr[i] = max(maxarr[i - 3] + arr[i - 1] + arr[i], maxarr[i - 2] + arr[i]);
	}


	cout << maxarr[n - 1];
	delete maxarr;
	delete arr;
	system("pause");
}