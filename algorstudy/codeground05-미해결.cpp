#include<iostream>
#include<algorithm>
using namespace std;

long long datas[100002][3];
int N;


int main() {

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N;
		for (int i = 1; i <= N; i++)
			cin >> datas[i][0];
		
		long long maxs = 0;
		datas[0][0] = 1;
		datas[0][1] = 1;
		for (int i = 0; i <= N; i++)
		{
			if (datas[i][0] < datas[i + 1][0]) {
				datas[i + 1][1] = datas[i][1] + 1;
				maxs = max(maxs,datas[i+1][1]);
			}
			else if (datas[i][0] == datas[i + 1][0]) datas[i + 1][1] = datas[i][1];
		}
		long long maxs2 = 0;
		datas[N+1][0] = 1;
		datas[0][2] = 1;
		for (int i = N+1; i >= 1; i--)
		{
			if (datas[i-1][0] > datas[i][0]) {
				datas[i-1][2] = datas[i][2] + 1;
				maxs2 = max(maxs2, datas[i - 1][2]);
			}
			else if ((datas[i - 1][0] == datas[i][0])) datas[i - 1][2] = datas[i][2];
		}

		cout << "Case#" << tc << endl;
		cout << min(maxs2,maxs) << endl;
	}
	system("pause");
}