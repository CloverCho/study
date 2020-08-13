// 백준 2011 암호코드
// 제출 결과: 성공

#include <stdio.h>
#include <string.h>

int number[5001];
int len;
int record[5001];

int main()
{
	char s[5001];
	scanf("%s", s);
	len = strlen(s);

	for (int i = 0; i < len; ++i)
	{
		number[i] = s[i] - '0';
	}

	if (len == 1 && number[0] == 0)
	{
		printf("0\n");
		return 0;
	}


	// 초기화
	number[len] = -1;	// end
	record[len] = 1;
	record[len-1] = 1;
		
	
	int error = 0;
	for (int i = len - 2; i >= 0; --i)
	{
		// 0이 앞에 붙여질 경우
		if (number[i] == 0)
		{
			if (i == 0)
			{
				error = 1;
				break;
			}
			if (number[i - 1] != 1 && number[i - 1] != 2)
			{
				error = 1;
				break;
			}
			if (number[i + 1] == 0){
				error = 1;
				break;	
			}

			

			// 안전한 0일 경우
			record[i] = record[i+1];
		}

		// 1이 앞에 붙여질 경우
		// [ 1, 나머지 ] 의 개수 + [ (1 + 다음자리), 나머지 ] 의 개수
		else if (number[i] == 1)
		{
			// 다음 자리가 0이 아닌 경우
			if (number[i+1] != 0){
				// 다음다음 자리가 0이 아닌 경우
				if (number[i+2] != 0){
					record[i] = record[i + 1] + record[i + 2];
				}
				else {
					record[i] = record[i+1];
				}
			}
			else {	// 다음 자리가 0인 경우
				record[i] = record[i+1];
			}
		}
		// 2가 앞에 붙여질 경우
		else if (number[i] == 2)
		{
			// 다음 자리가 0인 경우
			if ( number[i+1] == 0){
				record[i] = record[i+1];
			}			
			// 다음 자리가 1~6인 경우, 1이 앞에 붙여지는 경우와 동일
			else if (number[i + 1] >= 1 && number[i + 1] <= 6)
			{
				// 다음다음 자리가 0이 아닌 경우
				if (number[i+2] != 0){
					record[i] = record[i + 1] + record[i + 2];
				}
				else {
					record[i] = record[i+1];
				}
			}
			// 다음 자리가 7~9인 경우
			else
			{
				record[i] = record[i + 1];
			}
		}
		// 3 ~ 9 가 앞에 붙여질 경우
		else
		{	
			// xx30, xx40 등등 방지
			if (i == len -2 && number[len-1] == 0){
				error = 1;
				break;
			}

			record[i] = record[i+1];
		}

		record[i] %= 1000000;

	}
	if (error == 1)
	{
		printf("0\n");
		return 0;
	}

	printf("%d\n", record[0]);
	return 0;
}
