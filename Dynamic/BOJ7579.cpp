#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;


int memory[100];
int dp[100][10001];
int cost[100];
int minvalue = 987654321;
int n, m;


int main()
{
	scanf("%d %d", &n, &m);
	int i, j;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &memory[i]);
	}
	int sum = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &cost[i]);
		sum += cost[i];
	}
	for (i = 0; i < 100; i++)
		dp[i][0] = 0;
	for(j=1; j<=sum;j++)//cost를 이용한 knapsack원리(메모리가 가장 크게 dp에 저장)
		for (i = 0; i < 100; i++)
		{
			if (i == 0)
			{
				if (j - cost[i] >= 0)
					dp[i][j] = memory[i];
				else
					dp[i][j] = 0;
			}
			else if (j - cost[i] >= 0)
			{
				dp[i][j] = max(dp[i - 1][j - cost[i]] + memory[i], dp[i - 1][j]);
			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	for (j = 0; j <= sum; j++)
	{
		for (i = 0; i < 100; i++)
		{
			if (m <= dp[i][j] && j < minvalue)
			{
				minvalue = j;
				break;
			}
		}
	}
	printf("%d", minvalue);
}
