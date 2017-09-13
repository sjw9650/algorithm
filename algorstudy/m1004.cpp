#include <iostream>
#include <cmath>
using namespace std;
class planets {
private:
	int x, y, r;
	
public:
	planets() {}
	planets(int x, int y, int r) {
		this->x = x;
		this->y = y;
		this->r = r;
	}
	void setplanets(int x, int y, int r) {
		this->x = x;
		this->y = y;
		this->r = r;
	}
	int IsIn(int a, int b) {
		int k = (a - x)*(a - x) + (b - y)*(b - y) - r*r;
		if ( k > 0) return 1;
		else return 0;
	}
};
planets datas[50];
int main() {
	int T;
	cin >> T;
	for(int jk=0;jk<T;jk++)
	{
		int x1, x2, y1, y2, n;
		cin >> x1 >> y1 >> x2 >> y2>>n;

		int st = 0, ed = 0, sum = 0;

		for (int i = 0; i < n; i++)
		{
			int t1, t2, t3;
			cin >> t1 >> t2 >> t3;
			datas[i].setplanets(t1, t2, t3);

			if (datas[i].IsIn(x1, y1) == 0 && datas[i].IsIn(x2, y2) == 0)
				sum++;
			if (datas[i].IsIn(x1, y1) == 0) st++;
			if (datas[i].IsIn(x2, y2) == 0) ed++;
		}
		cout << st + ed - 2*sum << endl;
	}
	system("pause");
}