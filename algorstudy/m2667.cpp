#include<iostream>
#include<list>
#include<string>
using namespace std;
int arr[27][27];
int n;
int seek(int x, int y,int c) {
	arr[x][y] = -1;
	if (arr[x + 1][y] == 1) c = seek(x + 1, y, c+1);
	if (arr[x][y+1] == 1) c = seek(x, y+1, c+1);
	if (arr[x - 1][y] == 1) c = seek(x - 1, y,c+1);
	if (arr[x][y-1] == 1) c= seek(x, y-1,c+1);
	return c;
}
int main() {
	
	cin >> n;

	for (int i = 1; i <= n; i++){
		string t;
		cin >> t;
		for (int j = 0; j < n; j++)
		{
			arr[i][j + 1] = (int)t.at(j)-48;
		}

	}
	int counts = 0;
	list<int> result;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == 1) {
				counts++;
				result.push_back(seek(i, j, 1));
			}
		}
	}
	result.sort();
	cout << counts << endl;
	for (list<int>::iterator li = result.begin(); li != result.end(); li++)
		cout << *li << endl;

}