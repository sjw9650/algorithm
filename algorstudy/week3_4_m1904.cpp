#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	long long *dp = new long long[n + 1];

	dp[1] = 1;

	if(n>=2) dp[2] = 2;

	for (int i = 3; i < n + 1; i++)
		dp[i] = (dp[i - 1] + dp[i - 2])% 15746;

	cout << dp[n];

	system("pause");
}
