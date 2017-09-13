#include <iostream>
using namespace std;
void polypr()
{
	int V, E,poly;
	cin >> V >> E;
	poly = 2 - V + E;
	cout << poly << endl;
}
int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
		polypr();
}