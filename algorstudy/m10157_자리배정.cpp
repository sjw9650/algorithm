#include<iostream>
using namespace std;
int main() {
	int c, r, k,x,y;
	cin >> c >> r >> k;

	if (k > c*r) {
		cout << 0;
		return 0;
	}
	if (k == 1)
	{
		cout << "1 1";
		return 0;
	}

	int counts = 3;
	int temp = 1;
	while (k >= temp) {

		counts++;

		int tmp = counts / 4;
		
		if (counts % 4 == 0) {

			temp += r - 2 * tmp + 1;

			if (k < temp||(r-2*tmp+1)<=0)
			{
				temp -= r - 2 * tmp + 1;

				x = tmp; y = tmp;

				while (k != temp)
				{
					temp++;
					y++;
				}
				cout << x << " " << y;
				return 0;
			}
		}
		else if (counts % 4 == 1)
		{

			temp += c - 2 * tmp + 1;

			if (k < temp||(c - 2 * tmp + 1) <= 0)
			{
				x = tmp; y = tmp + r - 2 * tmp + 1;

				temp -= c - 2 * tmp + 1;

				while (k != temp)
				{
					temp++;
					x++;
				}
				cout << x << " " << y;
				return 0;
			}
		}
		else if (counts % 4 == 2)
		{
			temp += r - 2 * tmp + 1;
			if (k < temp)
			{
				x = tmp + c - 2 * tmp + 1; 
				y = tmp + r - 2 * tmp + 1;

				temp -= r - 2 * tmp + 1;

				while (k != temp)
				{
					temp++;
					y--;
				}
				cout << x << " " << y;
				return 0;
			}
		}
		else {
			temp += c - 2 * tmp + 1;
			if (k < temp)
			{
				x = tmp + c - 2 * tmp + 1; y = tmp;
				temp -= c - 2 * tmp + 1;
				while (k != temp)
				{
					temp++;
					x--;
				}
				cout << x << " " << y;
				return 0;
			}
		}
	}
	
}