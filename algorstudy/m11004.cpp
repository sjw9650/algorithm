#include <iostream>
#include <vector>
#include <algorithm>
int a[5000000];
int main() {
	int n, k; 
	std::ios::sync_with_stdio(false);
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::nth_element(a, a + k - 1, a + n);
	std::cout << a[k - 1];
	return 0;
}