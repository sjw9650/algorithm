#include <iostream>
#include <string>
using namespace std;
int groupword(string a) {
	int n = a.length();
	string *dp = new string[n];
	int k = 0;
	dp[0].assign(a, 0, 1);
	for (int i = 1; i < n; i++)
	{
		string temp;
		temp.assign(a,i,1);

		int m=dp[i - 1].find(temp);

		if (m == -1)
		{
			dp[i] = dp[i - 1];
			dp[i].append(temp);
			k++;
		}
		else if (m == k) {
			dp[i] = dp[i - 1];
		}
		else {
			return 0;
		}
	}

	return 1;
}
int main() {
	int n;
	cin >> n;

	int k = 0;

	for (int i = 0; i < n; i++)
	{
		string word;
		cin >> word;
		k = k + groupword(word);
	}
	cout << k;
}