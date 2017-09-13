#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	int n = 0;

	cin >> n;


	int *arr = new int[n+1];

	arr[1] = 0;
	for (int i = 2; i < n +1; i++)
	{	
		if (i % 3 == 0)
		{
			if (arr[i - 1] >= arr[i / 3]) arr[i] = arr[i / 3] + 1;
			else arr[i] = arr[i - 1] + 1;
		}
		else if (i % 2 == 0)
		{
			if (arr[i - 1] >= arr[i / 2]) arr[i] = arr[i / 2] + 1;
			else arr[i] = arr[i - 1] + 1;
		}
		else
		{
			arr[i] = arr[i - 1] + 1;
		}
	}
	cout << arr[n];
	
	system("pause");
}