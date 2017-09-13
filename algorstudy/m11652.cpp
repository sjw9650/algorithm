#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	sort(p.begin(), p.end());

	long long result = p[0];
	int stack_= 1;
	int max_stack_=0;
	for (int i = 1; i < n; i++) {
		if (p[i - 1] == p[i]) {
			stack_++;
			if (stack_ > max_stack_) {
				max_stack_ = stack_;
				result = p[i];
			}
		}
		else {
			stack_ = 1;
		}

	}
	cout << result;
}