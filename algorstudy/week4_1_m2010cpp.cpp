#include <iostream>

using namespace std;
int main() {
	int n;
	cin >> n;
	int *arr = new int[n];
	int *dp = new int[n+1];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	dp[0] = 1;
	for (int i = 1; i < n + 1; i++) dp[i] = dp[i - 1]-1 + arr[i-1];
	cout << dp[n];
}