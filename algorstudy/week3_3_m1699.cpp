	#include <iostream>
	#include <algorithm>
	#include <cmath>

	using namespace std;

	int temp2[318];
	int dp[100001];

	int main()
	{
		int n;
		int k = 0;
		cin >> n;

		dp[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			dp[i] = 10000;
			if (pow(i, 2) <= n)
			{
				temp2[k] = pow(i, 2);
				k++;
			}
		}
		for (int i = 1; i <= n ; i++)
		{
			for (int j = 0; j < k; j++)
			{
				if (i == temp2[j])
				{
					dp[i] = 1;
					break;
				}
				else if (i >= temp2[j])
					dp[i] = min(dp[i], dp[i - temp2[j]] + 1);
				else break;
			}
		}
		cout << dp[n];
	}
