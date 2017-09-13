#include<iostream>
#include<algorithm>
using namespace std;
int datas[1001];
int dp[1001];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> datas[i];
	int maxs = datas[1];
	dp[1] = datas[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = datas[i];
		for (int j = i - 1; j >= 1; j--)
		{
			if (datas[i] > datas[j]) dp[i] = max(dp[i], dp[j] + datas[i]);
			maxs=max(dp[i],maxs);
		
		}
	}
	cout << maxs;
}