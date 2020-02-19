#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

long long dp[36];

void init()
{
	int i;
	for (i = 0; i < 36; i++)
		dp[i] = 0;
}

int main(void)
{
	init();//dp배열 초기화
	int n;
	int t[15];
	int p[15];
	int i, j;
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		scanf("%d %d", &t[i], &p[i]);
	}
	if (t[n] == 1)//마지막 날 일을 할 수 있는지 없는지.
		dp[n] = p[n];
	else
		dp[n] = 0;
	for (i = n-1; i >=1; i--)
	{
		if (i + t[i]-1 <= n)//i날째 일을 할 수 있다면
		{
			dp[i] = p[i] + dp[i + t[i]];
		}
		dp[i] = max(dp[i], dp[i + 1]);//i날째 일을 한경우와, i+1일 째의 경우를 비교해서 더 큰값을 저장.

	}
	cout << dp[1];
}
