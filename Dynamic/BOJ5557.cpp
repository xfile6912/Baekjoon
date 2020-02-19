#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int info[100];
long long dp[21][100];

void init()
{
	int i, j;
	for (i = 0; i < 21; i++)
	{
		for (j = 0; j < 100; j++)
			dp[i][j] = 0;
	}
}

int main(void)
{
	int i, j;
	int n;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &info[i]);
	}
	dp[info[0]][0] = 1;//dp배열의 기저
	for (j = 1; j < n-1; j++)
	{
		for (i = 0; i < 21; i++)
		{
			if (dp[i][j - 1] != 0)
			{
				if (i + info[j] <= 20)
					dp[i + info[j]][j]+=dp[i][j-1];//숫자i를 j-1번째 숫자까지의 경우에서 만들수 있고, j번째에 i+info[j]를 만들 수있다면 이 경우의 수를 dp[i+info[j][j]에 더해줌.
				if (i - info[j] >= 0)
					dp[i - info[j]][j] += dp[i][j - 1];//숫자i를 j-1번째 숫자까지의 경우에서 만들수 있고, j번째에 i-info[j]를 만들 수 있다면 이 경우의 수를 dp[i-info[j][j]에 더해줌.
			}
		}
	}
	printf("%lld", dp[info[n - 1]][n - 2]);
}
