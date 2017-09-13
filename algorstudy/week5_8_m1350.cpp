#include<iostream>

using namespace std;
int siz[1001];
int main()
{
	int N, clu;
	cin >> N;
	unsigned long long sum = 0;
	for (int i = 0; i < N; i++) cin >> siz[i];
	cin >> clu;
	for (int i = 0; i < N; i++) {
		sum += siz[i] / clu;
		if (siz[i] % clu > 0) sum++;
	}
	unsigned long long result = sum*clu;
	cout << result;

	system("pause");
}