#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> datas;
int dp[100];
int n, k;

bool Compare(int n, int m) { return n > m; }
int coin_select(int money) {
	int f_count = 0;
	if (dp[money] != 0) return dp[money];
	for (vector<int>::iterator vi = datas.begin(); vi != datas.end(); vi++) {
		if (money - (*vi) >= 0 ) {
			if (dp[money - *vi] == 0) {
				f_count += coin_select( money - *vi );
			}
		}
		else if (money - (*vi) == 0) {
			f_count++;
		}
	}

	dp[money] = f_count;
	return f_count;
}

int main() {
	int result_num;

	cin >> n >> k;

	
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		datas.push_back(temp);
	}

	sort(datas.begin(),datas.end(), Compare);
	result_num=coin_select(k);
	cout << result_num << endl;
	system("pause");
	
}