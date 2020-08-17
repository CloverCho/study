// 백준 14501 퇴사
// 제출 결과: 성공

#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int N;
int T[15], P[15];

int record[16];

int dp(int date)
{
	if (date == N)
		return 0; // 퇴사일
	if (date > N)
		return 0x7fffffff * -1;
	if (record[date] >= 0)
		return record[date];

	// 현재 날짜가 i인 경우 받을 수 있는 최대
	// = max ( 해당 날짜에 잡혀 있는 상담을 수행할 경우, 수행하지 않을 경우)
	// = max ( P[i] + dp(i + T[i]),  dp(i+1))
	record[date] = max(P[date] + dp(date + T[date]), dp(date + 1));
	return record[date];
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d %d", &T[i], &P[i]);
		record[i] = -1;
	}

	int ret = dp(0);
	printf("%d\n", ret);

	return 0;
}
