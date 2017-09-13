/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
long long max_num;
long long Answer;
int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		cin >> max_num;
		vector<long long> data_;
		for (int i = 0; i < max_num; i++) {
			long long temp = 0;
			cin >> temp;
			data_.push_back(temp);
		}
		long long temp_num = data_[0];
		int flag = 1;
		int count_ = 0;
		for (int i = 1; i < max_num; i++) {
			if (flag == 1) {
				if (temp_num >= data_[i]) temp_num = data_[i];
				else {
					count_++;
					flag = 0;
					temp_num = 0;
				}
			}
			else {
				temp_num = data_[i];
				flag = 1;
			}
		}
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).

		cout << "Case #" << test_case + 1 << endl;
		cout << count_`*2 << endl;
	}
	return 0;//Your program should return 0 on normal termination.
}