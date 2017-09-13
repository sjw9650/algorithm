#include <iostream>
#include <vector>
using namespace std;

int n, m;
int arr[1000][1000];
int store_result[1000000];

int dfs(int x,int y,int counts) {
	int temp_count = counts + 1;
	arr[x][y] = 0;
	if (x + 1 != n&&arr[x + 1][y] == 1) {
		temp_count = dfs(x+1,y,temp_count);
	}
	if (x != 0 && arr[x - 1][y] == 1) {
		temp_count=dfs(x-1,y,temp_count);
	}
	if (y != 0 && arr[x][y - 1] == 1)
	{
		temp_count = dfs(x,y-1,temp_count);
	}
	if (y + 1 != m && arr[x][y + 1] == 1) {
		temp_count = dfs(x,y+1,temp_count);
	}
	return temp_count;
}

int main() {
	cin >> n >> m;
	int c;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	cin >> c;
	vector<int> input;
	for (int i = 0; i < c; i++) {
		int temp;
		cin >> temp;
		input.push_back(temp);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr[i][j] == 1)
				store_result[dfs(i,j,0)]++;
	for (vector<int>::iterator vi = input.begin(); vi != input.end(); vi++) {
		cout << store_result[*vi] << endl;
	}

	system("pause");
}