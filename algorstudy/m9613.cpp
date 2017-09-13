#include <iostream>

using namespace std;

int main() {

	int test_case;
	cin >> test_case;
	for (int Test_case = 0; Test_case < test_case; Test_case++)
	{
		int k;
		long long result=0;
		cin >> k;
		int *input_data = new int[k];
		for (int i = 0; i < k; i++) {
			cin>>input_data[i];
		}
		for (int i = 0; i < k-1; i++) {
			int a, b, r;
			for (int j = i+1; j < k; j++)
			{
				a = input_data[i];
				b = input_data[j];
				r = a%b;
				while (r != 0) {
					a = b;
					b = r;
					r = a % b;
				}

				result += b;
			}


		}

		cout << result << "\n";


	}
	system("pause");
}