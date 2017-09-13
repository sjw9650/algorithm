#include <iostream>
#include <queue>


int main() {
	int n, m;
	std::cin >> n >> m;
	std::queue<int> data_queue;
	std::queue<int> result_queue;
	for (int i = 1; i <= n; i++) data_queue.push(i);
	int temp;
	std::cout << "<";
	while (!data_queue.empty()) {
		for (int i = 0; i < m-1; i++) {
			temp = data_queue.front();
			data_queue.pop();
			data_queue.push(temp);
		}
		temp = data_queue.front();
		data_queue.pop();
		if (data_queue.empty()) {
			std::cout << temp << ">";
		}
		else {
			std::cout << temp << ", ";
		}
	}
	std::cout << "\n";
}