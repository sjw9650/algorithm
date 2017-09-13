#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	int n = 0;
	int ak = 0; 
	long long max = -1001;
	cin >> n;

	long long *arr =new long long [n];
	long long sum = 0;
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i] < 0) k++;
	}
	long long *temp = new long long[k+1];

	if (k >= n) ak = 1;

	if(ak==0)
	{
	int a = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < 0)
		{
			temp[a] = sum;
			a++;
		}
		sum = sum + arr[i];
		if (sum < 0) sum = 0;
	}
	temp[a] = sum;
	a++;
	
	for (int i = 0; i < a; i++)
	{
		if (max < temp[i]) max = temp[i];
	}
	}
	else
	{
		for (int i = 0; i < n; i++)
			if (arr[i] > max) max=arr[i];
	}
	cout << max;
	system("pause");
}