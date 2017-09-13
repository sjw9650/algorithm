// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
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
	/* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다. 
	만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,
	그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	//freopen("input.txt", "r", stdin);

	//setbuf(stdout, NULL);

	int TC;
	int test_case;
	checking();
	cin >> TC;	// cin 사용 가능
	for (test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오.
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

		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);	// cout 사용 가능
		cout << result << endl;
	}
	system("pause");
	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}