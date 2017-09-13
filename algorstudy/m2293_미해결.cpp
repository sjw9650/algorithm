#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, k;	
int arr[101];
int dp[10001];
vector<int> indp[101];

int coindiv(int num) {
	int re=0;
	int indps =101;
	int index[10001] = { 0 };
	for (int i = n - 1; i >= 0; i--)
	{
		if (arr[i] == num) { indps = i; break; }
	}
	for (int i = n-1 ; i >= 0; i--)
	{
		if (arr[i] == num) re++;
		else if (arr[i] < num) {
			
			if (indps != 101) indp[indps].push_back(arr[i]);

			cout << num - arr[i];
			re += dp[num - arr[i]];
			
			if (!indp[i].empty()) {

				for (vector<int>::iterator vi = indp[i].begin(); vi != indp[i].end(); vi++)
				{
					re -= dp[*vi];
				}
			}
		}
		else break;
	}
	return re;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(begin(arr), end(arr), [](int a, int b) {return a > b;});
	
	dp[arr[n-1]] = 1;

	for (int i = arr[n-1]+1; i <= k; i++)
	{
		dp[i] = coindiv(i);
		cout << "dp [" << i << "] = " << dp[i] << endl;
	}

	system("pause");
}