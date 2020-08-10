// 백준 10844 쉬운 계단 수
// 제출 결과 : 시간 초과

#include <stdio.h>



int N;
long long int ret;
long long int denominator = 1000000000;


void dp(int count, int number)
{
	if (count == N){
		++ret;	
		return;
	} 
	
	// number = 1~8 인 경우  dp(n, number) = dp(n+1, number+1) + dp(n+1, number-1)
	// number = 0 인 경우 dp(n, 0) = dp(n+1, 1)
	// number = 9 인 경우 dp(n, 9) = dp(n+1, 8)

	if (number == 0) {
		dp(count + 1, 1);
	}
	else if (number == 9) {
		dp(count + 1, 8);
	}
	else {
		dp(count + 1, number + 1);
		dp(count + 1, number - 1);
	}

}


int main()
{
	scanf("%d", &N);


	// 맨 앞은 1~9
	for (int i = 1; i <= 9; ++i)
		dp(1, i);

	ret %= denominator;
	printf("%lld\n", ret);
	return 0;
}
