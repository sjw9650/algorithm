#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
	int n;
	cin >> n;
	int **arr = new int *[n];
	for (int i = 0; i < n ; i++)
	{
		arr[i] = new  int[2];
		for (int j = 0; j < 2; j++) cin >> arr[i][j];
	}
	int k = arr[0][1];
	for (int i = 1; i < n; i++)
	{
		k = max(k,max(arr[i][1],arr[i][0]));
	}
	long long **dp = new long long *[k + 1];
	for (int i = 0; i < k+1; i++)
	{
		dp[i] = new long long[k+1];
	}
	dp[1][0] = 1;
	dp[1][1] = 1;

	for (int i = 2; i < k + 1; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			if (j == 0 || j == i) dp[i][j] = 1;
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << dp[arr[i][1]][arr[i][0]] << endl;
	}

	system("pause");
}