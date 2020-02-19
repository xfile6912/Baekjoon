#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int info[101];
int cache[1001][101];
int n, s, m;

int main(void)
{

	scanf("%d %d %d", &n, &s, &m);
	int i, j;
	for (i = 1; i <= n; i++)
		scanf("%d", &info[i]);
	cache[s][0] = 1;//현재 s음;


	for (j=1; j<=n; j++)
	{
		for (i = 0; i <= m; i++)
		{
			if (cache[i][j-1] == 1)
			{
				if (i + info[j] <= m)
					cache[i + info[j]][j] = 1;//j번째에 i+info[j]을 낼 수 있는 경우가 있으므로 1;
				if (i - info[j] >= 0)
					cache[i - info[j]][j] = 1;//j번째에 i-info[j]음을 낼 수 있으므로 1; 
			}
		}
	}
	int flag = -1;//갈수 없는경우
	for (i = 0; i <= m; i++)
	{
		if (cache[i][n] == 1)
			flag = i;//n번째에 낼수 있는 음 중에 최대값 찾음
	}
	printf("%d", flag);
}
