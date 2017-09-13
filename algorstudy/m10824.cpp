#include <iostream>
#include <string.h>
using namespace std;

int main() {
	int A, B, C, D;

	cin >> A >> B >> C >> D;

	char buf1[16];
	char buf2[16];

	memset(&buf2, 0, sizeof(char)*16);
	memset(&buf1, 0, sizeof(char) * 16);

	snprintf(buf1, sizeof(buf1), "%d%d", A, B);
	snprintf(buf2, sizeof(buf2), "%d%d", C, D);

	long long temp1 = atoll(buf1);
	long long temp2 = atoll(buf2);

	cout << temp1 + temp2 << "\n";
	
}
