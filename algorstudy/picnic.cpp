#include <iostream>
#include <vector>
using namespace std;

int n, m;
int datas[92];

int requ(int *arr,int c, int kk) {

	int ak = 0;
	
	int *temp_arr = new int[n];

	
	for (int i = 0; i < n; i++){
		temp_arr[i]=arr[i];
	}


	for (int k = 0; k < n; k++) {
		if (temp_arr[k] == 0)
		{
			ak = 1;
			break;
		}
	}

	if (ak == 0)
	{
		c++;
		return c;
	}

	for (int j = kk; j < m; j++)
	{
		if (temp_arr[datas[2 * j]] == 0 && temp_arr[datas[2 * j + 1]] == 0)
		{
			temp_arr[datas[2 * j]] = 1; 
			temp_arr[datas[2 * j + 1]] = 1;

			c=requ(temp_arr,c,j+1);
			
			temp_arr[datas[2 * j]] = 0;
			temp_arr[datas[2 * j + 1]] = 0;
		}
		
	}
	
	return c;
}

int main() {

	int C;
	cin >> C;
	for (int i = 0; i < C; i++)
	{
		cin >> n >> m;
		
		int *arr = new int[n];

		for (int k = 0; k < n; k++) {
			arr[k] = 0;
		}
		for (int j = 0; j < 2 * m; j++)
			cin >> datas[j];

		int counts = requ(arr,0,0);
		
		cout << counts << endl;
	}
	system("pause");

}