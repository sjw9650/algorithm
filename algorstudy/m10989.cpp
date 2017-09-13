#include <iostream>

using namespace std;
int index_[10001];
int main() {
	int n;
	cin >> n;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		index_[temp]++;
	}

	for (int i = 1; i <= 10000; i++) {
		if (index_[i] != 0) {
			for (int j = 0; j < index_[i]; j++)
				cout << i << "\n";
		}
	}
}
