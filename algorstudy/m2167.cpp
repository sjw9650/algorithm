#include <iostream>

using namespace std;

int n, m, T, **arr;
int twoarry(int i, int j, int x, int y) {
	int temp = 0;
	for (int a = i - 1; a < x; a++)
		for (int b = j - 1; b < y; b++)
			temp += arr[a][b];
	return temp;
}
int main() {
	cin >> n >> m;
	arr = new int*[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}
	cin >> T;
	int *arr2 = new int[T];
	for (int i = 0; i < T; i++) {
		int temp[4] = { 0,0,0,0 };
		for (int j = 0; j < 4; j++) cin >> temp[j];
		arr2[i]=twoarry(temp[0], temp[1], temp[2], temp[3]);
	}
	for (int i = 0; i < T; i++)
		cout << arr2[i] << endl;
	system("pause");

}