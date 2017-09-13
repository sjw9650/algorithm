#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
class tagets {
private:
	int x, y, r;

public:
	tagets() {}
	tagets(int x, int y, int r) {
		this->x = x;
		this->y = y;
		this->r = r;
	}
	int IsIn(int x1,int y1, int r1) {

		if (x1 == x&&y1 == y) {
			if (r1 == r) return -1;
			else return 0;
		}
		else {
			double result = sqrt((double)((x - x1)*(x - x1) + (y - y1)*(y - y1)));
		
			if ((r1 + r) == result|| max(r1, r) - min(r1, r) == result) return 1;
			else if (r1 + r > result && result > max(r1, r) - min(r1, r)) return 2;
			else return 0;
		}

	}
	int getR() { return r; }
	int getX() { return x; }
	int getY() { return y;}
};
int main() {
	int T;
	cin >> T;
	for (int jk = 0; jk<T; jk++)
	{
		int sum = 0, ed = 0, st = 0;
		int x1, y1, r1, x2, y2, r2;

		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		tagets datas(x1, y1, r1);
		cout << datas.IsIn(x2,y2,r2) << endl;
	}
}