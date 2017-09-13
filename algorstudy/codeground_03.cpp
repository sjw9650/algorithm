// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

long long checkpoint[100000];

void checking() {
	checkpoint[0] = 1;
	for (int i = 1; i < 100000; i++)
	{
		checkpoint[i] = checkpoint[i - 1] + i;
	}
}

void moves(int *x,int *y ,char inputs) {

	switch (inputs)
	{
	case 'D':
		(*y)++;
		break;
	case 'R':
		(*x)++;
		break;
	case 'U':
		(*y)--;
		break;
	case 'L':
		(*x)--;
		break;
	default:
		break;
	}
}

long long seeknum(int x,int y,int N) {

	int temp = x + y;
	int tx=x, ty=y;

	long long result=0;

	int ck = 0;

	if (temp > N - 1)
	{
		tx = N - 1 - x;
		ty = N - 1 - y;
		ck = 1;
	}

	temp = tx + ty;

	result = checkpoint[temp];

	if(temp%2==0)
		for (int i = 0; i < tx; i++) result++;
	else 
		for (int i = 0; i < ty; i++) result++;


	if (ck == 0)
		return result;
	else {
		return N*N + 1 - result;
	}

}

int main(int argc, char** argv) {
	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�. 
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	//freopen("input.txt", "r", stdin);

	//setbuf(stdout, NULL);

	int TC;
	int test_case;
	checking();
	cin >> TC;	// cin ��� ����
	for (test_case = 1; test_case <= TC; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.
		long long result=1;
		int N, K;
		cin >> N >> K;
		string inputs;
		cin >> inputs;
		int x=0, y = 0;

		for (int i = 0; i < K; i++)
		{
			char temp= inputs.at(i);
			moves(&x, &y, temp);
			result += seeknum(x,y,N);
		}

		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);	// cout ��� ����
		cout << result << endl;
	}
	system("pause");
	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}