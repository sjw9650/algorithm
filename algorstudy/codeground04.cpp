#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

#define maxnum 600001
#define dpnum 300000
int dp[maxnum][2];

int main(int argc, char** argv) {

	int TC;
	int test_case;

	cin>>TC;	// cin 사용 가능
	for (test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오.

		int N;
		cin >> N;

		int *inputs = new int[N];

		for (int i = 0; i < N; i++) {
			cin >> inputs[i];
		}

		dp[inputs[0]+ dpnum][0] = 1;
		dp[inputs[0]+ dpnum][1] = 0;

		int counting=0;

		for (int i = 1; i < N; i++)
		{
			dp[inputs[i]+ dpnum][0] = 1;

			int n = 0;
			int m = 0;
			
			for (int j = 0; j < i; j++) {
				if (dp[inputs[i] - inputs[j] + dpnum][1] == 1|| dp[inputs[i] - inputs[j] - inputs[j] + dpnum][0] == 1){
					counting++;
					break;
				}
			}
			for (int j = 0; j <= i; j++)
			{
				dp[inputs[j] + inputs[i] + dpnum][1] = 1;
			}

		}

		for (int i = 0; i < maxnum; i++)
		{
			dp[i][0] = 0;
			dp[i][1] = 0;
		}

		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);	// cout 사용 가능
		cout << counting << endl;
	}
	system("pause");
}