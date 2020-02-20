#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

#define mod 1000000000

int dp[30001][30];

int main() {
	int i, j;
	for (i = 0; i <= 30000; i++)
	{
		for (j = 0; j < 30; j++)
		{
			dp[i][j] = 0;
		}
	}
	int n;
	int m;
	int chu[30];
	int ball[7];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &chu[i]);
	
	dp[15000 + chu[0]][0] = 1;
	dp[15000 - chu[0]][0] = 1;
	dp[15000][0] = 1;
	for(j=1; j<n; j++)
		for (i = 0; i <= 30000; i++)
		{
			if (dp[i][j - 1] == 1)
				dp[i - chu[j]][j] = 1;
			if (dp[i][j - 1] == 1)
				dp[i][j] = 1;

			if (dp[i][j - 1] == 1)
				dp[i + chu[j]][j] = 1;
		}
	scanf("%d", &m);
	int k;
	int flag;
	for (k = 0; k < m; k++)
	{
		scanf("%d", &ball[k]);
		ball[k] = ball[k] + 15000;
	}
	for (k = 0; k < m; k++)
	{
		flag = 0;
		if (ball[k] < 30001)
		{
			for (i = 0; i < 30; i++)
			{
				if (dp[ball[k]][i] == 1)
					flag = 1;
			}
		}
		if (flag == 1)
			printf("Y ");
		else
			printf("N ");
	}
}
