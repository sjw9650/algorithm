#include<iostream>
#include<algorithm>
using namespace std;
int arr[3001];
int in_data[30000];
int maxs;
int result;
int main() {
	int n, d, k, c;
	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++)
	{
		cin >> in_data[i];
	}
	maxs = 1;
	arr[c] = 1;
	for (int i = 0; i < k; i++)
	{
		if (arr[in_data[i]] == 0) maxs++;
		arr[in_data[i]]++;
	}
	result = maxs;
	for (int i = 1; i < n; i++) {
		arr[in_data[(i - 1) % n]]--;
		if (arr[in_data[(i - 1) % n]] == 0) maxs--;
		if (arr[in_data[(i + k - 1) % n]] == 0) maxs++;
		arr[in_data[(i + k - 1) % n]]++;
		result = max(maxs, result);
	}
	cout << result;
}