#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int n;
	cin >> n;
	long long *dp = new long long [n + 1];
	dp[1] = 0;
	for(int i=2;i<n+1;i++)
	{
		if (i % 3 == 0)
		{
			dp[i] = min(dp[i / 3], dp[i- 1]) + 1;
		}
		else if (i % 2 == 0)
		{
			dp[i] = min(dp[i/ 2], dp[i- 1]) + 1;
		}
		else
		{
			dp[i] = dp[i - 1] + 1;
		}
		
	}
	cout <<dp[n];
}

/*
int main() {

int n, m;
cin >> n;
long long *dp = new long long [n + 1];
m = n+1;
dp[1] = 0;
while (--n)
{
if ((m - n) % 3 == 0)
{
dp[m - n] = min(dp[(m - n) / 3], dp[m - n - 1]) + 1;
}
else if ((m - n) % 2 == 0)
{
dp[m - n] = min(dp[(m - n) / 2], dp[m - n - 1]) + 1;
}
else
{
dp[m - n] = dp[m - n - 1] + 1;
}

}

cout <<dp[m-1];

*/