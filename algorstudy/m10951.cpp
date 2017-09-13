#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair <int, int>> in_data(n);
	for (int i = 0; i < n; i++) {
		cin >> in_data[i].second >> in_data[i].first;
	}
	sort(in_data.begin(),in_data.end());
	for (int i = 0; i < n; i++) {
		cout << in_data[i].second << " " << in_data[i].first << "\n";
	}
}