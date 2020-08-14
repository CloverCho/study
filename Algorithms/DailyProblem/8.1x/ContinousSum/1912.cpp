// 백준 1912번 연속합
// 제출 결과: 성공

#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int sum[100001] = {0, };

// 핵심 : 누적합 배열을 구한 다음, 배열의 두 원소의 차를 이용
// 1부터 i 번쨰 입력값의 합을 S(i) 라 할 경우,
// i번쨰부터 j번째 입력값의 합은 S(j) - S(i-1)
// 이 값이 최대가 되는 i및 j를 찾아낸다.
int main()
{
	scanf("%d %d", &N, &sum[1]);

	int number;
	int start = 0, end = 1; // 최댓값의 시작 지점, 끝 지점

	int ret = sum[1];

	int p = 0; // 누적합 중 최솟값의 지점
	int flag = 0;	// 초기에 연속으로 음수가 나오는지 체크

	int ret_negative = sum[1];	// 죄다 음수인 경우 최댓값

	if (sum[1] < 0){
		p = 1;
		flag = 1;
	}


	for (int i = 2; i <= N; ++i)
	{
		scanf("%d", &number);
		sum[i] = sum[i - 1] + number; // 누적합 계산

		if ( number < 0 && flag == 1){
			p = i;
			ret_negative = max(ret_negative, number);

			if (i == N){
				ret = ret_negative;	
			}	
				
			continue;
		}
		else {
			flag = 0;
		}
		

		if ( sum[i] - sum[p] > ret){
			start = p;
			end = i;
			ret = sum[end] - sum[start];
			continue;
		}

		
		
		if (sum[i] < sum[p])
		{
			p = i;
		}
	}

	printf("%d\n", ret);
	return 0;
}
