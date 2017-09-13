
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	unsigned long *arr = new unsigned long[n + 1];

	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i < n + 1; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	for(int i=0;i<n;i++)	cout << arr[i]<<endl;
	system("pause");
	return 0;
}