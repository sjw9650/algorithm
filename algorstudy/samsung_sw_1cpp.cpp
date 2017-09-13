#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int N, M;
int datas[500][500];
int visited[500][500];

bool compare(int temp1,int temp2) {

	int tx1 = temp1 / 1000;
	int ty1 = temp1 % 1000;
	int tx2 = temp2 / 1000;
	int ty2 = temp2 % 1000;
	return (datas[tx1][ty1] < datas[tx2][ty2]);
}

int searching_max(int x, int y) {

	for (int i = 0; i < N+2; i++)
		for (int j = 0; j < M+2; j++)
			visited[i][j]=0;

	vector<int> queu;
	int temp = 0;
	int tx, ty;
	int return_num = 0;
	queu.push_back(1000*x+y);

	for(int i=0;i<3; i++)
	{
		temp = queu.back();
		queu.pop_back();

		tx = temp / 1000;
		ty = temp % 1000;
		visited[tx][ty] = 1;
		return_num += datas[tx][ty];

		if (tx - 1 >= 0) {
			if (visited[tx - 1][ty] == 0) {
				visited[tx - 1][ty] = 1;
				queu.push_back(1000*(tx-1)+ty);
			}
		}
		if (tx + 1 < N) {
			if (visited[tx + 1][ty] == 0) {
				visited[tx + 1][ty] = 1;
				queu.push_back(1000 * (tx + 1) + ty);
			}
		}
		if (ty - 1 >= 0) {
			if (visited[tx][ty-1] == 0) {
				visited[tx][ty-1] = 1;
				queu.push_back(1000 * (tx) + ty-1);
			}
		}
		if (ty + 1 < M) {
			if (visited[tx][ty+1] == 0) {
				visited[tx][ty+1] = 1;
				queu.push_back(1000 * (tx) + ty+1);
			}
		}
		sort(queu.begin(),queu.end(), compare);
	}

	temp = queu.back();
	queu.pop_back();
	tx = temp / 1000;
	ty = temp % 1000;
	return_num += datas[tx][ty];

	return return_num;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin>>datas[i][j];

	int result = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			result = max(result,searching_max(i,j));

	cout << result << endl;	
	
	system("pause");
	
}