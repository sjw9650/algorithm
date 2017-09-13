#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[101][101];
int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) arr[i][j] = 0;
			else arr[i][j]=101;
		}
	}

	for (int i = 1; i <= m; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		arr[t1][t2] = 1;
		arr[t2][t1] = 1;
	}


	for (int k = 1; k <=n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if(arr[i][k]+arr[k][j]<arr[i][j])
				{
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
	int index=0;
	int result = 101;
	for (int i = 1; i <= n; i++)
	{
		int k = 0;
		for (int j = 1; j <= n; j++)
		{
			k += arr[i][j];
		}
		if (k < result) index = i;
		result = min(k, result);
	}
	cout << index;

}