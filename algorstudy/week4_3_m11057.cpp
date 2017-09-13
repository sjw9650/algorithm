#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	long long dp1[10] = {1,1,1,1,1,1,1,1,1,1};
	long long *dp2 = new long long[10];
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			dp2[0] = dp1[0];
			for (int j = 1; j < 10; j++) dp2[j] = (dp2[j - 1] + dp1[j])%10007;
		}
		else {
			dp1[0] = dp2[0];
			for (int j = 1; j<10; j++) dp1[j] = (dp1[j - 1] + dp2[j])%10007;
		}
	}

	if (n % 2 == 1) cout<<dp2[9];
	else cout << dp1[9];

	system("pause");
}