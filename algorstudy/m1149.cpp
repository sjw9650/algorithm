#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	int **arr = new int*[n];
	long long **dp = new long long*[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[3];
		for (int j = 0; j < 3; j++) cin >> arr[i][j];
		dp[i] = new long long[3];
	}
	
	for (int i = 0; i < 3; i++) dp[0][i] = arr[0][i];

	for (int i = 1; i < n; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
	}
	cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
}