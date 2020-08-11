// 백준 2579번
// 제출결과 : 성공


#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int step[300];

// 각 높이에 대하여 두 가지 상태 : 포올짝 / 폴짝
int record[300][2];		


int dp(int height) {



	// 초기값 지정
	record[0][0] = step[0];
	record[0][1] = step[0];

	record[1][0] = step[1];
	record[1][1] = step[0] + step[1];
	
	for (int i = 2; i <= height; ++i)
	{
		// 포올짝 : 현재 값 + {이전 계단(2칸 아래)의 max(포올짝, 폴짝)} 
		record[i][0] = step[i] + max(record[i-2][0], record[i-2][1]);
		// 폴짝 = 이전 계단(1칸 아래)의 포올짝
		record[i][1] = step[i] + record[i-1][0];	
	}

	// 결과값
	int result = max(record[height][0], record[height][1]);
	
	return result;

}


int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &step[i]);

	int ret = dp(N-1);
	printf("%d\n", ret);

	return 0;
}
