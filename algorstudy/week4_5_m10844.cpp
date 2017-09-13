#include <iostream>

using namespace std;
int main() {
	int n;
	cin >> n;

	int dp[11] = { 0,1,1,1,1,1,1,1,1,1,9};
	int *dp2 = new int [11];
	
	for (int i = 1; i < n; i++)
	{
		if (i % 2 == 1)
		{
			dp2[10] = 0;
			for (int j = 0; j < 10; j++)
			{
				if (j == 0) dp2[0] = dp[1];
				else if (j == 9) dp2[9] = dp[8];
				else dp2[j] = (dp[j - 1] + dp[j + 1])%1000000000;

				dp2[10] = (dp2[10]+dp2[j]) % 1000000000;
			}
		}
		else
		{
			dp[10] = 0;
			for (int j = 0; j < 10; j++)
			{
				if (j == 0) dp[0] = dp2[1];
				else if (j == 9) dp[9] = dp2[8];
				else dp[j] = (dp2[j - 1] + dp2[j + 1]) % 1000000000;

				dp[10] = (dp[10] + dp[j]) % 1000000000;
			}
		}
	}

	if (n % 2 == 0)
		cout << dp2[10];
	else cout << dp[10];

	system("pause");
	
}