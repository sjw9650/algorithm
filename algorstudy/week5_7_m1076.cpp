#include <iostream>
#include <string>
using namespace std;

string arr[10];
int arr2[10];
int main() {
	arr[0] = "black";
	arr[1] = "brown";
	arr[2] = "red";
	arr[3] = "orange";
	arr[4] = "yellow";
	arr[5] = "green";
	arr[6] = "blue";
	arr[7] = "violet";
	arr[8] = "grey";
	arr[9] = "white";	
	long long result;
	for (int i = 0; i < 10; i++)
	{
		int k = 1;
		for (int j = 0; j < i; j++)
			k = k * 10;
		arr2[i]= k;
	}

	string str;
	for (int i = 0; i < 2; i++) {
		cin >> str;
		int k;
		for (int j = 0; j < 10; j++)
		{
			if (str == arr[j])
			{
				k = j;
				break;
			}
		}
		if (i == 0) result = k * 10;
		else result += k;
	}
	cin >> str;
	for (int j = 0; j < 10; j++)
	{
		if (str == arr[j])
		{
			result = result*arr2[j];
			break;
		}
	}
	cout << result;
}