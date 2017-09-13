#include <iostream>
using namespace std;
int main() {
	int T;
	cin >> T;
	int dp[101];
	dp[1] = 1;
	for (int i = 2; i < 101; i++)
	{
		int count = 0;
		dp[i] = dp[i - 1];
		for (int j = 2; j < i; j++) if (i%j == 0) count++;
		if (count % 2 == 1) dp[i]++;
	}
	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n;
		cout << dp[n] << endl;
	}
}