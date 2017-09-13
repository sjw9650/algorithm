#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	int n = 0;

	cin >> n;
	int *pro = new int[n];
	int max=0;
	for (int i = 0; i < n; i++)
	{
		cin >> pro[i];
		if (max < pro[i]) max = pro[i];
	}

	unsigned long *arr = new unsigned long[max+1];

	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;

	for (int i = 6; i < max + 1; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 5];
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[pro[i]] << endl;
	}
	system("pause");
}