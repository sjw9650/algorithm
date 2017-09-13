#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct {
	int age;
	string name;
}Person;
bool compared(const Person p1,const Person p2) {
	return p1.age < p2.age;
}
int main() {
	int n;
	cin >> n;
	vector<Person> p(n);
	for (int i = 0; i < n; i++) {
		int temp_age;
		string temp_name;
		cin >> temp_age >> temp_name;
		p[i].age = temp_age;
		p[i].name = temp_name;
	}
	stable_sort(p.begin(), p.end(), compared);
	for (int i = 0; i < n; i++) {
		cout << p[i].age << " " << p[i].name << "\n";
	}
}