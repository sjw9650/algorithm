#include<iostream>
#include<algorithm>

using namespace std;

int A[50];
int B[50];

bool compare(int a, int b)
{
	return a > b;
}
int main() {
	int K;
	cin >> K;
	for (int i = 0; i < K; i++)
		cin >> A[i];

	for (int i = 0; i < K; i++)
		cin >> B[i];

	sort(A,A+K);
	sort(B, B + K, compare);
	int result = 0;
	for (int i = 0; i < K; i++) {
		result += A[i] * B[i];
	}
	cout << result;
}