#include<iostream>
#include<string>

using namespace std;

int resulting(string mem,string fan) {
	const char* temp1=mem.c_str();
	const char* temp2 = fan.c_str();;
	int counts = 0;
	int gap = fan.length()-mem.length();
	if (gap == 0) {
		if (fan.find("M") == -1||mem.find("M")==-1) {
			return 1;
		}
		else {
			if (mem.compare(fan) == 0) {
				return 0;
			}
			else {
				for (int i = 0; i < mem.length(); i++)
				{
					if (mem.at(i) == 'M'&&fan.at(i) == 'M') {
						return 0;
					}
					if (i == mem.length() - 1) return 1;
				}
			}
		}
	}
	else {
		if (fan.find("M") == -1 || mem.find("M") == -1) return (gap+1);
		for (int j = 0; j <= gap; j++)
		{
			for (int i = 0; i < mem.length(); i++)
			{
				if (temp1[i] == 'M' && temp2[i+j] == 'M')
					break;
				if (i == mem.length() - 1) counts++;
			}
		}
		return counts;
	}



}

int main() {
	int c;
	cin >> c;
	string memeber="";
	string fans="";
	for(int i=0;i<c;i++)
	{
		cin >> memeber >> fans;
		cout << resulting(memeber, fans) << endl;
	}
	system("pause");
}