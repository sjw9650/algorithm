#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n, k;
	scanf_s("%d %d", &n, &k);
	unsigned long long int **dp = NULL;
	dp = (unsigned long long int**)malloc(sizeof(unsigned long long int)* (n + 1));
	for (int i = 0; i < n + 1; i++)
	{
		dp[i] = (unsigned long long int*)malloc(sizeof(unsigned long long int)*(n + 1));
	}

	dp[1][0] = 1;
	dp[1][1] = 1;

	for (int i = 2; i < n + 1; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			if (j == 0 || j == i) dp[i][j] = 1;
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}

	printf("%lld \n", dp[n][k]);

}
