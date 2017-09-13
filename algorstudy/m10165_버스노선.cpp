#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct {
	int startp;
	int lastp;
	int num_r;
}Route;

bool Compare(Route a,Route b) {

	if (a.startp == b.startp) {
		return (a.lastp > b.lastp);
	}
	else
		return (a.startp < b.startp);
}

Route R_data[500000];

int main() {
	int N;
	cin >> N;
	int RN;
	cin >> RN;
	for (int i = 0; i < RN; i++)
	{
		int temp1,temp2;
		cin >> temp1 >> temp2;
		R_data[i].startp = min(temp1,temp2);
		R_data[i].lastp = max(temp1, temp2);
		R_data[i].num_r = i + 1;
	}
	sort(R_data,R_data+RN,Compare);

	for (int i = 0; i < RN; i++)
	{
		cout << R_data[i].startp << "  " << R_data[i].lastp<<"  "<< R_data[i].num_r << endl;
	}
	system("pause");
}