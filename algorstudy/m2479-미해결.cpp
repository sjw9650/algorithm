#include <iostream>
#include <algorithm>
#include <string>
#include <windows.h>
#include <vector>
#include <cmath>
using namespace std;

class haming {
private:
	int integers;
	string strings;
	int index;
	int visited;
	vector<haming> adjham;
	int ij;
public:
	haming(string strings, int index)
	{
		size_t Length;
		this->strings = strings;
		this->integers = stoi(strings, &Length, 2);
		this->index = index;
		this->visited = 0;
	}
	haming()
	{

	}
	void sethaming(string strings, int index)
	{
		size_t Length;
		this->strings = strings;
		this->integers = stoi(strings, &Length, 2);
		this->index = index;
		this->visited = 0;
		this->ij = 0;
	}
	int getIndex() { return index; }
	vector<haming> getHaming() { return adjham; }
	string getStrings() { return strings; }
	int getInts() { return integers; }
	int getVisited() { return visited; }
	void visiting() { this->visited = 1; }
	void adhaming(haming k)
	{
		this->adjham.push_back(k);
	}
};

haming arr[1001]; int n, k,st,en;
int where_is_from[1001];
vector<haming> printv;

void BFS(haming a) {
	vector<haming> temp = a.getHaming();

	vector<haming>::iterator vi;
	
	for (vi=temp.begin();vi!=temp.end();vi++)
	{
		haming temps = *vi;
		if (arr[temps.getIndex()].getVisited() == 0) {
			where_is_from[temps.getIndex()] = a.getIndex();
			printv.push_back(temps);
			arr[temps.getIndex()].visiting();
		}
	}
}


int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		string tmp; 
		cin >> tmp;
		arr[i].sethaming(tmp,i);
		string tmp2;
		tmp = arr[i].getStrings();
		for (int j = 1; j < i; j++)
		{
			tmp2 = arr[j].getStrings();
			int coun=0;
			for (int ii = 0; ii < k; ii++) {
			
				if (tmp.at(ii) != tmp2.at(ii))
				{
					coun++;
					if (coun >= 2) break;
				}
			}
			if (coun == 1) {
				arr[i].adhaming(arr[j]);
				arr[j].adhaming(arr[i]);
			}
		}
	}
	cin >> st >> en;

	printv.push_back(arr[st]);
	where_is_from[st] = -1;
	int akaka = 0;
	arr[st].visiting();
	while (!printv.empty())
	{
		haming wtemp = printv.at(akaka);
		
		BFS(arr[wtemp.getIndex()]);

		akaka++;

		if (wtemp.getIndex() == en) {
			
			break;
		}
		if (akaka >= printv.size()) {
			cout << -1<<endl;
			return 0;
			break;
		}
	}
	vector<int> prinv;
	int prin = en;
	while (prin!=-1) {
		prinv.push_back(prin);
		prin = where_is_from[prin];
	}

	vector<int>::reverse_iterator pvi;
	for (pvi = prinv.rbegin(); pvi != prinv.rend(); pvi++) {
		cout << *pvi << " ";
	}

	system("pause");

}