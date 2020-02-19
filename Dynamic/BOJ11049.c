#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;


int info[500][2];
int dp[500][500];
int n;
int main(void)
{
	scanf("%d", &n);
	int i, j;
	int lastj;
	for (i = 0; i < n; i++)
		cin >> info[i][0] >> info[i][1];
	i = 0; j = 0;
	int k;
	int mintemp;
	lastj = j;
	while (1)//dp[i][j] => i번째 행렬부터 j번째행렬 까지의 최솟값 
	{
		if (i == 1 && j == n)
			break;
		if (j == n)
		{
			i = 0;
			j = lastj + 1;
			lastj = j;
		}
		if (i == j)
			dp[i][j] = 0;//dp배열의 기저;
		else
		{
			mintemp = -1;
			for (k = i; k <= j - 1; k++)//모든 경우 훑어봄.
			{
				if (mintemp == -1)
					mintemp = dp[i][k] + dp[k + 1][j] + info[i][0] * info[k][1] * info[j][1];
				else if (mintemp > dp[i][k] + dp[k + 1][j] + info[i][0] * info[k][1] * info[j][1])
					mintemp = dp[i][k] + dp[k + 1][j] + info[i][0] * info[k][1] * info[j][1];
			}
			dp[i][j] = mintemp;
		}
		
		i++;
		j++;
	}
	printf("%d", dp[0][n - 1]);
}
