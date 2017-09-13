#include <iostream>

using namespace std;

int main() {

	int test_case;
	cin >> test_case;
	for (int i = 0; i < test_case; i++)
	{
		int n, m;

		cin >> n >> m;
		int gcd, gdb;
		int a, b, r;
		a = n; b = m;
		r = a%b;
		while (r != 0) {
			a = b;
			b = r;
			r = a % b;
		}
		gcd = b;
		gdb = n*m / gcd;
		cout <<gdb<<"\n";


	}
}