#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int T;
	cin >> T;
	int *arr = new int[T];
	int maxs = 0;
	for (int i = 0; i < T; i++)
	{
		cin >> arr[i];
		maxs = max(maxs, arr[i]);
	}
	int **dp = new int*[maxs + 1];
	for (int i = 0; i <= maxs; i++)
	{
		dp[i] = new int[2];
	}
	dp[0][0] = 1; dp[0][1] = 0;
	if (maxs>=1)	dp[1][0] = 0; dp[1][1] = 1;
	for (int i = 2;i <= maxs; i++)
	{
		for (int j = 0; j < 2; j++)
			dp[i][j] = dp[i-1][j]+dp[i-2][j];
	}

	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < 2; j++)
			cout << dp[arr[i]][j]<<" ";
		cout << endl;
	}
}