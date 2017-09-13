#include <iostream>
#include <algorithm>

using namespace std;
int n, k, *arr, **arr2,*dp;
int temp[100001];
int DFS(int output) {
	if (dp[output] != -1) return dp[output];
	
	int count = 0;
	dp[output] = arr[output];

	for (int i = 0; i < k; i++)
	{
		if (arr2[i][1] == output) {
			temp[count] = arr2[i][0];
			count++;
		}
	}

	for (int i = 0; i < count; i++) {
		dp[output] = max(dp[output],DFS(temp[i])+arr[output]);
	}

	return dp[output];
}
int main() {
	int T;
	cin >>T;

	for(int l=0;l<T;l++){

		cin >> n >> k;
		arr = new int[n + 1];
		arr2 = new int*[k];
		dp = new int[n+1];
		int output;
		for (int i = 1; i < n + 1; i++)
		{
			cin >> arr[i];
			dp[i] = -1;
		}
		for (int i = 0; i < k; i++) {
			arr2[i] = new int[2];
			for (int j = 0; j < 2; j++) cin >> arr2[i][j];
		}
		cin >> output;
		cout << DFS(output) << endl;
	}
	system("pause");

}