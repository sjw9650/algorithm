#include <iostream>
#include <algorithm>
using namespace std;
int n;
int *l_arr;
int **dp;
int *r_arr;
int cardgaem(int left,int right) {
	
	if (left==0&&right==0)
	{
		int temp[3] = { -1,-1,-1 };
		if (l_arr[left] > r_arr[right])
		{
			temp[0] = cardgaem(1,0);
			temp[1] = cardgaem(1, 1);
			temp[2] = cardgaem(0,1)+r_arr[0];
		}
		else
		{
			temp[0] = cardgaem(1, 0);
			temp[1] = cardgaem(1, 1);
			temp[2] = -1;

		}
		return max(temp[0], max(temp[1], temp[2]));
	}
	else if(left<=n-1&&right==n-1)
	{
		int temp = -1;
	
		if (l_arr[left] > r_arr[right])
		{
			return r_arr[right];
		}
		else
		{
			temp=cardgaem(left + 1, right);
			if (temp == -1 || temp==0) return 0;
			else return temp;
		}
		
	}
	else if (left >= n || right>=n)
	{
		return 0;

	}else 
	{
		if (dp[left][right] != -1) {
			return dp[left][right];
		}
		else
		{
			int temp[3] = { -1,-1,-1 };
			if (l_arr[left] > r_arr[right])
			{
				temp[0] = cardgaem(left + 1, right);
				temp[1] = cardgaem(left + 1, right + 1);
				temp[2] = cardgaem(left, right + 1) + r_arr[right];
			}
			else
			{
				temp[0] = cardgaem(left + 1, right);
				temp[1] = cardgaem(left + 1, right + 1);
				temp[2] = -1;
			}
			dp[left][right] = max(temp[0], max(temp[1], temp[2]));
			return max(temp[0], max(temp[1], temp[2]));
		}
	}
}

int main() {
	cin >> n;
	l_arr = new int[n];
	r_arr = new int[n];
	dp = new int*[n];
	int l_max = 0;
	int r_max = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> l_arr[i];
		l_max = max(l_max,l_arr[i]);
		dp[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> r_arr[i];
		r_max = max(r_max, r_arr[i]);
		for (int j = 0; j < n; j++)
		{
			dp[i][j] = -1;
		}
	}

	if (l_max > r_max)
	{
		int sum=0;
		for (int i = 0; i < n; i++) sum += r_arr[i];
		cout << sum;
	}
	else
	{
		int sum = cardgaem(0, 0);
		cout << sum;
	}
	system("pause");
}