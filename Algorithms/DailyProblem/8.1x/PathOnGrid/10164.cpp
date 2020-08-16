// 백준 10164번 격자상의 경로
// 제출 결과: 성공



#include <stdio.h>



int N, M, K;
int dp[16][16] = {0, };


int main() {
	scanf("%d %d %d", &N, &M, &K);
	// 초기화
	dp[1][1] = 1;
	int sx = 2;
	int ny = 0, nx = 0;
	int exit = 0;


	// 1부터 K까지 경로 계산
	for (int y = 1; y <= N; ++y){
		for (int x = sx; x <= M; ++x){
			dp[y][x] = dp[y-1][x] + dp[y][x-1];
			if ((y-1) * M + x == K)	{
				ny = y, nx = x;
				exit = 1;
				break;
			}
		}
		sx = 1;
		if(exit == 1)	break;
	}

	// K부터 끝까지 경로 계산
	if (ny != 0 || nx != 0){

		// 초기화
		for (int y = ny + 1; y <= N; ++y)
			dp[y][nx] = dp[ny][nx];
		for (int x = nx + 1; x <= M; ++x)
			dp[ny][x] = dp[ny][nx];

		// 다시 계산
		for (int y = ny + 1; y <= N; ++y)
			for (int x = nx + 1; x <= M; ++x)
				dp[y][x] = dp[y-1][x] + dp[y][x-1];
	}

	printf("%d\n", dp[N][M]);

	
	return 0;
}
