#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
int dp[101][101][101];

int mod = 1000000007;

int main()
{
	int n, l, r;



	scanf("%d %d %d", &n, &l, &r);
	long long temp;
	dp[1][1][1] = 1;
	int i, j, k;
	for (i = 2; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			for (k = 1; k <= n; k++)
			{
				temp = (dp[i - 1][j - 1][k]+ dp[i - 1][j][k - 1]) % mod + ((long long)dp[i - 1][j][k] * (i - 2))%mod;
				dp[i][j][k] = (int)(temp%mod);
			}
		}
	}
	printf("%d", dp[n][l][r]);
}
