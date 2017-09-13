/*
#include<iostream>
#include<algorithm>
using namespace std;
int arr[1001];
int dp[1001];
int main() {
	int n;
	cin >> n;
	for (int i =1; i <= n; i++) cin >> arr[i];
	int maxs = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = 1;
		for (int j = i - 1; j >= 1; j--)
		{
			if (arr[i] > arr[j]) dp[i]=max(dp[i],dp[j]+1);
			if (maxs < dp[i]) {
				maxs = dp[i]; 
				break;
			}
		}
	}
	cout << maxs;
	system("pause");
}

*/


#include<iostream>
#include<algorithm>
using namespace std;
int arr[1001];
int dp[1001];

int _lower_bounds(int start, int end, int target)
{
	int mid;
	while (end - start > 0)
	{
		mid = (start + end) / 2;

		if (dp[mid] < target)
			start = mid + 1;
		else end = mid;
	}
	return end + 1;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	int maxs = 1, i = 1;
	
	dp[maxs] = arr[i];
	
	i++;
	
	while (i <= n)
	{
		if (dp[maxs] < arr[i]) {
			maxs++;
			dp[maxs] = arr[i];
		}
		else
		{
			int tme = _lower_bounds(1, maxs, arr[i]);
			dp[tme-1] = arr[i];
		}
		i++;
	}
	
	for (int k = 1; k <= maxs; k++)
		cout << dp[k]<<endl;
	//cout << maxs;
	system("pause");
}
