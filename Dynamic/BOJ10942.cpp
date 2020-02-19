#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int info[2000];
int dp[2000][2000];
int main(void)
{
	int n;
	int m;
	int s, e;
	int i, j;
	int lastj;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &info[i]);
	i = 0, j = 0;
	lastj = j;
	while (1)
	{
		if (j == n)//i와 j가 계산할 범위가 넘어갔을 때
		{
			j = lastj + 1;
			lastj = j;
			i = 0;
		}
		if (i == 0 && j == n)//반복문 종료
			break;

		if (i == j)//숫자가 한개이면 팰린드롬임
			dp[i][j] = 1;
		else if (i + 1 == j)//숫자가 두개일 경우 두 숫자가 같은경우에만 팰린드롬임.
		{
			dp[i][j] = 0;
			if (info[i] == info[j])
				dp[i][j] = 1;
		}
		else
		{
			dp[i][j] = 0;
			if (dp[i + 1][j - 1] == 1 && info[i] == info[j])//숫자가 3개이상일 경우 i+1부터 j-1까지가 팰린드롬이고 숫자[i]와 숫자[j]가 같아야 팰린드롬임.
				dp[i][j] = 1;
		}
		i++;
		j++;
	}



	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &s, &e);
		printf("%d\n", dp[s - 1][e - 1]);
	}
}
