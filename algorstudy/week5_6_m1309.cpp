#include<iostream>

using namespace std;
/*
int dp[100002][3];
int mod = 9901;
int main() {
	int N;
	cin >> N;

	dp[0][1] = 1; dp[1][1] = 2; dp[2][1] = 3;
	dp[0][2] = 1; dp[1][2] = 4; dp[2][2] = 2; dp[3][2] = 7;
	for (int i = 3; i <= N; i++)
	{
		int k = i % 3;
		dp[0][k] = 1;
		for (int j = 1; j < i; j++) {
			dp[j][k] = (dp[j - 1][(k + 1) % 3] + dp[j - 1][(k + 2) % 3] + dp[j][(k + 2) % 3]) % mod;
			dp[i + 1][k] = (dp[i + 1][k] + dp[j][k]) % mod;
		}
		dp[i][k] = 2;
		dp[i+ 1][k] = (dp[i][k] + dp[i + 1][k] + dp[0][k]) % mod;
	}
	cout << dp[N + 1][N % 3];
}
*/
int dp[100001];
int mod = 9901;
int main() {
	int N;
	cin >> N;
	dp[1] = 3;
	dp[2] = 7;
	for (int i = 3; i <= N; i++)
		dp[i] = (dp[i - 1] * 2 + dp[i - 2])%mod;
	cout << dp[N];
}