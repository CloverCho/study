//	백준 P1463 1로 만들기
//	제출 결과: 성공

#include <stdio.h>
#include <algorithm>


using namespace std;

int N;

int main()
{
	
	scanf("%d", &N);

	int record[1000001];
	record[1] = 0;		// 1의 경우 최솟값 0
	record[2] = 1;		// 2의 경우 최솟값 1
	record[3] = 1;		// 3의 경우 최솟값 1


	for (int number = 4; number <= N; ++number) {
		
		if (number % 6 == 0){
			record[number] = 1 + min(record[number-1], min(record[number/2], record[number/3]));
		}
		else if (number % 3 == 0){
			record[number] = 1 + min(record[number-1], record[number/3]);
		}
		else if (number % 2 == 0) {
			record[number] = 1 + min(record[number-1], record[number/2]);
		}
		else {
			record[number] = 1 + record[number-1];
		}

	}
		
	
	printf("%d\n", record[N]);		


	return 0;
}
