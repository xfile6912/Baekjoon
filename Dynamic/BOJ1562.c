#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;



int mod = 1000000000;

int main()
{
	int n;
	int i, j,k;
	scanf("%d", &n);
	int dp[10][101][1 << 10];
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j <= 100; j++)
			for(k=0; k<(1<<10);k++)
				dp[i][j][k] = 0;
	}
	for (i = 1; i < 10; i++)
	{
		
		dp[i][1][1<<i] = 1;
	}




		for (j = 2; j <= n; j++)
		{
			for (i = 0; i < 10; i++)
			{
				for (k = 0; k < 1024; k++)
				{
					if (i == 0)
					{
						dp[i][j][k|(1<<i)] += dp[i + 1][j - 1][k];
					}
					else if (i == 9)
					{
						dp[i][j][k | (1 << i)]+= dp[i - 1][j - 1][k];
					}
					else
					{
						dp[i][j][k | (1 << i)] += dp[i - 1][j - 1][k] + dp[i + 1][j - 1][k];
					}
					dp[i][j][k | (1 << i)] %= mod;
				}
			}
		}

		int result=0;
		for (i = 0; i < 10; i++)
		{
			result += dp[i][n][1023];
            result%=mod;
		}
		printf("%d", result);
}
