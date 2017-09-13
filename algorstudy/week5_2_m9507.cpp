#include<iostream>
using namespace std;
int main() {
	int T;
	cin >> T;
	unsigned long long dp[68];
	for (int i = 0; i < 68; i++) {
		if (i < 2) dp[i] = 1;
		else if (i == 2) dp[i] = 2;
		else if (i == 3) dp[i] = 4;
		else dp[i] = dp[i-1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
	}
	for (int i = 0; i < T; i++) {
		int temp;
		cin >> temp;
		cout << dp[temp] << endl;
	}
}