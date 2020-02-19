#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int dp[10][1001];

int main(void)
{
	int n;
	cin >> n;
	int i, j;
	for (i = 0; i < 10; i++)
	{
		dp[i][1] = 1;
	}
	for (j = 2; j <=n;j++ )
		for (i = 0; i < 10; i++)
		{
			if (i == 0)
				dp[i][j] = 1;
			else
			{
				dp[i][j] = dp[i - 1][j]%10007 + dp[i][j - 1]%10007;
				dp[i][j] %= 10007;
			}
		}
	int sum = 0;
	for (i = 0; i < 10; i++)
	{
		sum += dp[i][n];
		sum = sum % 10007;
	}
	printf("%d", sum);
}
