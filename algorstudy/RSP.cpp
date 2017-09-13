#include<iostream>
#include <ctime>
#include <stdlib.h>
#include <random>
#include <windows.h>
using namespace std;



int main() {

	int n;
	cin >> n;
	int Arr[3][3] = { { 0,2,1 },{ 1,1,1 },{ 0,0,0 } };
	long long *temp = new long long[n];
	long long *temp2 = new long long[n];
	long long *result = new long long[n];
	long long sum = 0;


	int next=1;

	srand((unsigned int)time(NULL));

	if (n == 0) next = rand()%3;
	else {
		for (int i = 0; i < n; i++)
		{
			int ak = rand() % 2;
			cin >> temp[i];
			cin >> temp2[i];
			if (temp[i] - temp2[i] == 1 || temp2[i] - temp[i] == 2) { result[i] = 2;  sum = sum + 3; }
			else if (temp[i] == temp2[i]) { result[i] = 1; sum = sum + 1;}
			else { result[i] = 0; }
			if (i >= 1)
			{
				Arr[temp2[i - 1]][result[i-1]] = temp2[i];
			}
			if (i < 30 || i % 13 == 0 || i / 11 == 3 || (i > 99 && i < 120) || i % 38 % 3 == 0) {
				int k = rand() % 45712;
				next = (rand() % 3 + k) % 3;
			}
			else if (i%3!=ak)
			{
				if (Arr[temp2[i]][result[i]] == 0) next = 1;
				else if (Arr[temp2[i]][result[i]] == 1) next = 2;
				else next = 0;
			}
			else
			{
				next = Arr[temp2[i]][result[i]];
			}
			}
			
	}


	cout << next;
	system("pause");
}