#include<iostream>
#include <algorithm> 
#include <windows.h>
using namespace std;
int main() {
	int T;
	cin >> T;
	int *n = new int[T];
	int maxs = 0;
	for (int i = 0; i < T; i++)
	{
		cin >> n[i];
		maxs=max(n[i], maxs);
	}
	int *all = new int[maxs+1];
	all[1] = 1;
	if (maxs >= 2)
	{
		all[2] = 2;
		if(maxs>=3) 	all[3] = 4;
	}
	for (int i = 4; i < maxs+1; i++) all[i] = all[i - 1] + all[i - 2] + all[i - 3];
	for (int i = 0; i < T; i++) cout << all[n[i]] << endl;

	system("pause");


}