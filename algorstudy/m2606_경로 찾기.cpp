#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class com {
private:
	int visited = 0;
	vector<int> linked;
public:
	void link(int a) {
		linked.push_back(a);
	}
	int visitable() { return visited; }
	void visiting() { this->visited = 1; }
	vector<int> getlinked() { return linked; }

};
int datas[5051][2];
com com_num[101];
int infection;
void BFS(com a)
{
	vector<int> temp = a.getlinked();
	vector<int>::iterator vi;
	vector<com> temp_arr;
	for (vi = temp.begin(); vi != temp.end(); vi++)
	{
		if (com_num[*vi].visitable() == 0)
		{
			com_num[*vi].visiting();
			infection++;
			temp_arr.push_back(com_num[*vi]);
		}
	}
	vector<com>::iterator vii;
	for (vii = temp_arr.begin(); vii != temp_arr.end(); vii++)
	{
		BFS(*vii);
	}
}
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> datas[i][0] >> datas[i][1];
		com_num[datas[i][0]].link(datas[i][1]);
		com_num[datas[i][1]].link(datas[i][0]);
	}
	com_num[1].visiting();
	BFS(com_num[1]);
	cout << infection;
}