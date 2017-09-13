#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef int score;
typedef struct {
	score kroean;
	score english;
	score math;
	string name;
}Person;
bool compared(const Person p1,const Person p2) {
	if (p1.kroean != p2.kroean) {
		return p1.kroean > p2.kroean;
	}
	else if(p1.english != p2.english) {
		return p1.english < p2.english;
	}
	else if (p1.math != p2.math) {
		return p1.math > p2.math;
	}
	else {
		return p1.name < p2.name;
	}
}
int main() {
	int n;
	cin >> n;
	vector<Person> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].name >> p[i].kroean >> p[i].english >> p[i].math;
	}
	sort(p.begin(), p.end(), compared);
	for (int i = 0; i < n; i++) {
		cout << p[i].name << "\n";
	}

}