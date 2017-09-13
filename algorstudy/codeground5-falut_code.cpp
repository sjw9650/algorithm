#include<iostream>
#include<algorithm>
using namespace std;

long long datas[100002];
long long datas2[100002];
int N;

void remove_block(int *counts,int f,int l) {

	(*counts)++;

	long long temp=0;
	int flag = 0;
	int nf=0,nl = 0;
	for (int i = f; i <= l; i++)
	{
		
		if (datas[i] != 0) {
			datas2[i] = min(min(datas[i-1],datas[i+1]), datas2[i]-1);
			if (datas2 != 0)
			{
				if (flag == 0) {
					flag = 1;
					nf = i;
				}
				nl = i;
			}
			
		}
		temp += datas2[i];
	}

	for (int i = 0; i < N + 2; i++)
	{
		datas[i] = datas2[i];
	}

	if (temp != 0) {
		remove_block(counts,nf,nl);
	}
}

int main() {

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N;
		for (int i = 1; i <= N; i++)
			cin >> datas[i];
		int counts = 0;

		remove_block(&counts,1,N);

		cout << "Case#" << tc << endl;
		cout << counts << endl;
	}
	system("pause");
}