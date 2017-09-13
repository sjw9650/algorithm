#include<iostream>
#include<algorithm>
int arr[1001];
int dp[1001];
using namespace std;
int main() {
	int A;
	int result=1;
	cin >> A;
	for (int i = 0; i < A; i++) {
		cin >> arr[i];
	}
	dp[0] = 1;
	for (int i = 1; i < A; i++)
	{
		dp[i] = 1;
		int cut = result;
		for (int j = i-1; j >=0; j--)
		{
			if (arr[j] < arr[i])
			{
				dp[i] = max(dp[j]+1,dp[i]);
				result = max(result, dp[i]);
				if (dp[i] == cut + 1) break;
			}
		}
	}
	cout << result;
}