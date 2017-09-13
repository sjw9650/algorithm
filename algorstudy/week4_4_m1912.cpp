#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int count = 0;
	cin >> n;
	int *arr = new int[n];
	long long *dp = new long long[n+1];
	dp[n] = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i] < 0) count++;
	}

	dp[0] = arr[0];
	dp[n] = dp[0];
	if(count>=n)
	{
	
		for (int i = 1; i < n; i++)
		{
			dp[i] = arr[i];
			dp[n] = max (dp[i],dp[n]) ;
		}
		cout << dp[n];
	}
	else{
		for (int i = 1; i < n; i++)
		{
			if (dp[i-1] < 0) dp[i-1] = 0;
			dp[i] = dp[i - 1] + arr[i];
			dp[n] = max(dp[n], dp[i]);

		}
		cout << dp[n];

	}
}