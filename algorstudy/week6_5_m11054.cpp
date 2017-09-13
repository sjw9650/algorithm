#include<iostream>
#include<algorithm>
using namespace std;
int datas[1001];
int dp[1001][2];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> datas[i];
	int maxs = 1;

	dp[1][0] = 1;
	dp[1][1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i][0] = 1;
		dp[i][1] = 1;
		for(int j=i-1;j>=1;j--)
		{
			if (datas[i] > datas[j])
			{
				dp[i][0] = max(dp[i][0], dp[j][0]+1);
			}
			else if (datas[i] < datas[j])
			{
				dp[i][1] = max(dp[i][1], max(dp[j][0]+1,dp[j][1] + 1));
			}
		
		}
		maxs = max(dp[i][0], max(maxs,dp[i][1]));
	}
	cout << maxs;
}