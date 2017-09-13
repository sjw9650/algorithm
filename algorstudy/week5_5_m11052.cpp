#include<iostream>
#include<algorithm>
using namespace std;
int dp[1002];
int arr[1001];
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	for (int i = 1; i <= N; i++)
	{
		dp[i] = arr[i];
		for (int j = 1; j < i; j++)
		{
			dp[i]=max(dp[i],dp[i-j]+dp[j]);
			if (j > i - j) break;
		}
	}
	cout << dp[N];
}