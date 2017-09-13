#include<iostream>
#include<algorithm>
#include<windows.h>
using namespace std;
int main() {
	int n, m;
	cin >> n;
	cin >> m;
	

	if (n > m)
	{
		if (m == 1)
			cout << n-1;
		else 
			cout << m*(n-1)+(m-1) ;
	}
	else
	{
		if (n == 1)
			cout << m-1;
		else
			cout << n*(m- 1) + (n - 1);
	}

	system("pause");
}