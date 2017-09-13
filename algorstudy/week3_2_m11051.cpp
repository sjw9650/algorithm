#include <iostream>

using namespace std;
int main()
{
	int n, k;
	cin >> n;
	cin >> k;
	long long **dp = new long long*[n + 1];
	for (int i = 0; i < n+1; i++)
	{
		dp[i] = new long long [n+1];
	}

	dp[1][0] = 1;
	dp[1][1] = 1;

	for (int i = 2; i < n+1; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			if (j == 0 || j == i) dp[i][j] = 1;
			else
				dp[i][j] = (dp[i-1][j-1] % 10007 +dp[i-1][j] % 10007)%10007;
		}
	}

	cout << dp[n][k];

	system("pause");
}
