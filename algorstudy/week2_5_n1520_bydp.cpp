#include<iostream>
#include<algorithm>
#include<windows.h>

using namespace std;

long long **arr;
int **adj;
int counts = 0;

void downhill(int n, int m, int k, int l)
{
	if (n == k&&m == l)
		counts++;
	else {
		if (k != 0 && arr[k][l] > arr[k - 1][l])
		{
			downhill(n, m, k - 1, l);
		}
		if (k != n&&arr[k][l] > arr[k + 1][l])
		{
			downhill(n, m, k + 1, l);
		}
		if (l != 0 && arr[k][l] > arr[k][l - 1])
		{
			downhill(n, m, k, l - 1);
		}
		if (l != m && arr[k][l] > arr[k][l + 1])
		{
			downhill(n, m, k, l + 1);
		}
	}
}

int main() {
	int n;
	int m;
	cin >> n;
	cin >> m;
	arr = new long long*[n];
	adj = new int *[n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = new long long[m];
		adj[i] = new int[m];
		for (int j = 0; j<m; j++)
		{
			cin >> arr[i][j];
		}
	}
	adj[0][0] = 1;
	downhill(n - 1, m - 1, 0, 0);
	cout << counts;
	system("pause");
}