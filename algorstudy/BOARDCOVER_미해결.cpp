#include <iostream>

using namespace std;

char temp_data[22][22];
int h, w;
int insert_Block(int x, int y){
	int temp = 0;

	int temp_bool = 0;

	for (int i = 1; i < 22; i++)
		for (int j = 1; j < 22; j++)
			if (temp_data[i][j] == '.') {
				temp_bool = 1;
				break;
			}

	if (temp_bool == 0) return 1;
	
	if (y == h&&x == w) return 0;
	
	temp_data[x][y]='#';

	if (x + 1 <= w&&y + 1 <= h) {
		if (temp_data[x + 1][y + 1] != '#'&&temp_data[x + 1][y] != '#') {
			temp_data[x + 1][y + 1] = '#';
			temp_data[x + 1][y] = '#';
			
			for (int i = x; i <= h; i++)
				for (int j = y; j <= w; j++)
					if (temp_data[i][j] == '.')
						temp+=insert_Block(i,j);

			temp_data[x + 1][y + 1] = '.';
			temp_data[x + 1][y] = '.';
		}

		if (temp_data[x + 1][y + 1] != '#'&&temp_data[x][y+1] != '#') {
			temp_data[x + 1][y + 1] = '#';
			temp_data[x][y+1] = '#';
			for (int i = x; i <= h; i++)
				for (int j = y; j <= w; j++)
					if (temp_data[i][j] == '.')
						temp += insert_Block(i, j);
			temp_data[x + 1][y + 1] = '.';
			temp_data[x ][y+1] = '.';
		}

		if (temp_data[x + 1][y] != '#'&&temp_data[x][y + 1] != '#') {
			temp_data[x + 1][y] = '#';
			temp_data[x][y + 1] = '#';
			for (int i = x; i <= h; i++)
				for (int j = y; j <= w; j++)
					if (temp_data[i][j] == '.')
						temp += insert_Block(i, j);
			temp_data[x + 1][y] = '.';
			temp_data[x ][y+1] = '.';
		}
	}
	 
	if (x + 1 <= w&&y - 1 >= 1) {
		if (temp_data[x + 1][y -1] != '#'&&temp_data[x + 1][y] != '#') {
			temp_data[x + 1][y - 1] = '#';
			temp_data[x + 1][y] = '#';

			for (int i = x; i <= h; i++)
				for (int j = y; j <= w; j++)
					if (temp_data[i][j] == '.')
						temp += insert_Block(i, j);

			temp_data[x + 1][y - 1] = '.';
			temp_data[x + 1][y] = '.';
		}
	}

	if (x - 1 >= 1 && y + 1 <= h) {
		if (temp_data[x - 1][y + 1] != '#'&&temp_data[x - 1][y] != '#') {
			temp_data[x - 1][y + 1] = '#';
			temp_data[x - 1][y] = '#';

			for (int i = x; i <= h; i++)
				for (int j = y; j <= w; j++)
					if (temp_data[i][j] == '.')
						temp += insert_Block(i, j);

			temp_data[x - 1][y + 1] = '.';
			temp_data[x - 1][y] = '.';
		}
	}
	if (x + 1 <= w&&y - 1 >= 0) {
		if (temp_data[x + 1][y] != '#'&&temp_data[x][y - 1] != '#') {
			temp_data[x + 1][y] = '#';
			temp_data[x][y - 1] = '#';
			for (int i = x; i <= h; i++)
				for (int j = y; j <= w; j++)
					if (temp_data[i][j] == '.')
						temp += insert_Block(i, j);
			temp_data[x + 1][y] = '.';
			temp_data[x][y - 1] = '.';
		}
	}

	temp_data[x][y] = '.';

	return temp;

}

int main() {
	int c;
	cin >> c;
	for (int cases = 1; cases <= c; cases++)
	{
		cin >> h >> w;
		for (int i = 1; i <= h; i++){
			for (int j = 1; j <= w; j++)
				cin >> temp_data[i][j];
		}

		int result = 0;

		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++) 
				if (temp_data[i][j] != '#') {
					result = insert_Block(i, j);
					i = h+1;
					break;
				}
			

		cout <<result<<endl ;
	}

	system("pause");
}