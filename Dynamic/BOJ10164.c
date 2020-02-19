#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

long long info[15][15];


int main(void)
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int y, x;
	long long result;
	int i, j;
	if (k == 0)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (i == 0 || j == 0)
					info[i][j] = 1;//초기화
				else
					info[i][j] = info[i - 1][j] + info[i][j - 1];//i,j까지의 경로는 i-1,j까지의 경로와 i,j-1까지의 경로를 합한 경우이다.
			}
		}
		cout<< info[n - 1][m - 1];
	}
	else
	{
		y = (long long)(k - 1) / m;//중간지점의 좌표 계산
		x = (long long)(k - 1) % m;//중간지점의 좌표 계산
		for (i = 0; i <=y ; i++)
		{
			for (j = 0; j <= x; j++)
			{
				if (i == 0 || j == 0)
					info[i][j] = 1;
				else
					info[i][j] = info[i - 1][j] + info[i][j - 1];
			}
		}
		result = info[y][x];
		for (i = y; i <n; i++)
		{
			for (j = x; j <m; j++)
			{
				if (i == y || j == x)
					info[i][j] = 1;
				else
					info[i][j] = info[i - 1][j] + info[i][j - 1];
			}
		}
		result *= info[n - 1][m - 1];//경우의수는 중간지점까지의 경로의 수와 중간지점부터 끝지점까지 경로의 수를 곱해야함.
		cout << result;
	}
}
