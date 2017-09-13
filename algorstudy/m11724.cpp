#include<iostream>
#include<vector>
using namespace std;

class peak {
private:
	int visited = 0;
	vector<int> linked;
public:
	void linking(int k) { linked.push_back(k);}
	vector<int> getLinked() { return linked; }
	void visiting() { visited = 1; }
	int getvisited() { return visited; }
};
peak cc[1001];
void seek(peak k) {
	vector<int> temp = k.getLinked();
	for (vector<int>::iterator vi = temp.begin(); vi != temp.end(); vi++)
	{
		if (cc[*vi].getvisited() != 1)
		{
			cc[*vi].visiting();
			seek(cc[*vi]);
		}
	}
}
int main() {
	int n, m;
	int result=0;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		cc[t1].linking(t2);
		cc[t2].linking(t1);
	}
	for (int i = 1; i <= n; i++)
	{
		if (cc[i].getvisited() == 0)
		{
			result++;
			seek(cc[i]);
		}
	}
	cout << result;

}