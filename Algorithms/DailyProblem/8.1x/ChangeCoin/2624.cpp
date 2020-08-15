// 백준 2624	동전 바꿔주기

#include <stdio.h>

int T, k, ret;
int price[100], count[100];
int record[100][100001] = {
	0,
}; // record[coinIndex][Price];

int dp(int index, int value)
{

	if (value < 0)
	{
		return 0;
	}
	else if (value == 0)
	{
		return 1;
	}

	if (index == k - 1 || record[index][value] > 0)
	{
		return record[index][value];
	}

	int sum = 0;
	for (int i = 0; i <= count[index]; ++i)
	{
		if (value < price[index] * i) break;
		sum += dp(index + 1, value - price[index] * i);
	}

	record[index][value] = sum;

	return sum;
}

int main()
{
	scanf("%d %d", &T, &k);
	for (int i = 0; i < k; ++i)
	{
		scanf("%d %d", &price[i], &count[i]);
	}

	// 초기값 입력
	for (int i = 0; i <= count[k - 1]; ++i)
	{
		record[k - 1][price[k - 1] * i] = 1;
	}

	int ret = dp(0, T);
	printf("%d\n", ret);

	return 0;
}
