#include <iostream>
#include <algorithm>
using namespace std;
int *arr;
int k;
int n;
int *dp;
int trianglenum(int index, int depth) {
	if (depth >= n) return arr[index];
	else if (dp[index] != -1) return dp[index];
	else dp[index] = max(trianglenum(index + depth, depth + 1) + arr[index], trianglenum(index + depth + 1, depth+1) + arr[index]);
}

int main() {
	cin >> n;
	k = n*(n + 1) / 2;
	arr = new int[k];
	dp = new int[k];
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		dp[i] = -1;
	}
	cout << trianglenum(0,1);
	system("pause");

}