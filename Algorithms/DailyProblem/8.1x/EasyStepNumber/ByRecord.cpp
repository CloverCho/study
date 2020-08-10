// 백준 10844번  쉬운 계단 수
// 제출 결과 : 성공



#include <stdio.h>



int N;
long long int denominator = 1000000000;

long long int record[100][10] = {0, };

int StepNumber(int number)
{
	// record를 채운다.
	// record[N-1][M] : M 으로 시작하는 N 자리의 계단 수의 개수

	// N 자리의 계단 수의 총 개수 : record[N-1][1~9] 의 합


	// 초기값: 한 자리 수일 때
	for (int i = 0; i < 10; ++i) {
		record[0][i] = 1; 
	}


	// record 채우기

	if (N >= 2) {
		
		for (int digit = 1; digit < N; ++digit) {

			// 앞자리 0 
			record[digit][0] = record[digit-1][1];

			// 앞자리 9
			record[digit][9] = record[digit-1][8];

			// 앞자리 1~8			
			for (int i = 1; i <= 8; ++i) {
				record[digit][i] = record[digit-1][i-1] + record[digit-1][i+1];

			// 오버플로우가 발생하지 않도록 범위 제한  - 안하면 N=70 일때 음수가 나옴
				record[digit][i] %= denominator;
			}
		}

	}



	// 결과 계산

	long long int sum = 0;
	for (int i = 1; i <= 9; ++i) {
		sum += record[N-1][i];
	}

	sum %= denominator;

	return sum;
	
}


int main()
{
	scanf("%d", &N);

	long long int ret = StepNumber(N);
	printf("%lld\n", ret);
	return 0;
}
