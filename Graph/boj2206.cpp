#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int n, m;
int cache[1000][1000][2][4];//3차원배열의 [2]이부분은 [0]이면 벽을 더이상 부술수 없고 [1]인경우 부술 수 있음//[4]부분은 어디서 왔는지 저장
int visited[1000][1000];
int map[1000][1000];//맵 저장
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };
void init(int n, int m) {
	int i, j,k,l;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			for (k = 0; k < 2; k++)
			{
				for (l = 0; l < 4; l++)
					cache[i][j][k][l] = -2;
			}
			visited[i][j] = 0;
		}
	}
}
int dfs(int y, int x, int hammer, int from)//hammer가 1이면 벽을 부술 수 있는 경우가 아직 한번있음
{
	int temp;
	int i,j;
	int nexty;
	int nextx;
	if (y == n - 1 && x == m - 1)//dfs 종료조건
		return 1;

	int& ret = cache[y][x][hammer][from];

	if (ret != -2)
		return ret;
	ret = 987654321;
	if (hammer == 1)
	{
		for (i = 0; i < 4; i++)//nexty, nextx 벽에 해머를 쓰지 않은경우
		{
			nexty = y + dy[i]; nextx = x + dx[i];
			if (nexty >= 0 && nexty < n && nextx >= 0 && nextx < m && map[nexty][nextx] == 0 && visited[nexty][nextx] == 0)
			{
				visited[nexty][nextx] = 1;
				temp = dfs(nexty, nextx, 1, i);
				if (temp != -1)
				{
					ret = min(ret, temp + 1);
				}
				visited[nexty][nextx] = 0;
			}
		}
		for (i = 0; i < 4; i++)
		{
			
			nexty = y + dy[i]; nextx = x + dx[i];
			if (nexty >= 0 && nexty < n && nextx >= 0 && nextx < m && map[nexty][nextx] == 1 && visited[nexty][nextx] == 0)//nexty, nextx벽에 해머를 쓴경우;
			{	
				temp = 987654321;
				int temp1;
				visited[nexty][nextx] = 1;
				temp1 = dfs(nexty, nextx, 0, i);
				if (temp1 != -1)
				{
					temp = min(temp, temp1);
				}
				visited[nexty][nextx] = 0;
				for (j = 0; j < 4; j++)
				{
					int nexty=y+dy[j], nextx=x+dx[j];
					if (j == i)
						continue;
					else
					{
						if (nexty >= 0 && nexty < n && nextx >= 0 && nextx < m && map[nexty][nextx] == 0 && visited[nexty][nextx] == 0)//i번째 벽에 해머를 썼으므로 나머지 벽에는 해머를 쓰면 안된다.
						{
							visited[nexty][nextx] = 1;
							temp1 = dfs(nexty, nextx, 0, i);
							if (temp1 != -1)
							{
								temp = min(temp, temp1);
							}
							visited[nexty][nextx] = 0;
						}
					}
				}
				ret = min(ret, temp + 1);
			}
		}
	}
	for (i = 0; i < 4; i++)
	{
		nexty = y + dy[i]; nextx = x + dx[i];
		if (nexty >= 0 && nexty < n && nextx >= 0 && nextx < m && map[nexty][nextx]==0 && visited[nexty][nextx]==0)
		{
			visited[nexty][nextx] = 1;
			temp = dfs(nexty, nextx, 0, i);
			if (temp != -1)
			{
				ret = min(ret, temp + 1);
			}
			visited[nexty][nextx] = 0;
		}
	}
	if(ret==987654321)
		return ret=-1;
	return ret;
}
int main(void)
{

	
	int i, j;//for문
	scanf("%d %d", &n, &m);
	init(n,m);//visited와 cache배열 초기화
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	visited[0][0] = 1;
	printf("%d", dfs(0, 0,1,0));
}
