#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int t, w;
int cache[3][1000][31];
int info[1000];

int solve(int start, int time, int w)
{
	int& ret = cache[start][time][w];


	if (w == 0)//더 이상 이동할 수 없으므로 현재 위치에서 계속 머물러서 얻을수 있는 값 리턴
	{
		ret = 0;
		for (int i = time; i < t; i++)
		{
			if (start == info[i])
				ret++;

		}
		return ret;
	}
	if (time == t)
		return 0;

	if (ret != -1)
		return ret;

	ret = 0;
	if (start == info[time])//현재 위치에 자두가 떨어지는경우 ret는 1, 안떨어지는 경우는 0;
		ret = 1;

	if (start == 1)
	{
		ret += max(solve(1, time + 1, w), solve(2,time+1, w-1));
	}
	else
	{
		ret += max(solve(2, time + 1, w), solve(1, time + 1, w - 1));
	}
	return ret;
}


int main(void)
{
	int i, j, k;

	scanf("%d %d", &t, &w);
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < t; j++)
		{
			for (k = 0; k <= w; k++)
				cache[i][j][k] = -1;
		}
	}
	for (i = 0; i < t; i++)
		scanf("%d", &info[i]);
	printf("%d", max(solve(1, 0, w), solve(2,0,w-1)));//시작과 동시에 이동하지 않는경우와, 이동하는 경우 비교
}
