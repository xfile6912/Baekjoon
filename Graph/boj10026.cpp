#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int n;
char info[100][100];
int dir[2][4] = { {-1,0,1,0},{0,-1,0,1} };
int visited[100][100];
int colorcnt=0;//색약이 아닌 사람이 봤을 때의 구역의 수;
int colorweakcnt=0;//색약인 사람이 봤을때의 구역의수;
void init() {
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			visited[i][j] = 0;
	}
}

void dfs(int y, int x)
{
	visited[y][x] = 1;
	int nexty, nextx;
	int i, j;
	for (i = 0; i < 4; i++)
	{
		nextx =x+ dir[0][i];
		nexty =y+ dir[1][i];
		if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < n && visited[nexty][nextx] == 0 && info[nexty][nextx]==info[y][x])
		{
			dfs(nexty, nextx);
		}
	}
}
void changeforweak()
{
	int i, j;
	for(i=0; i<n; i++)
		for (j = 0; j < n; j++)
		{
			if (info[i][j] == 'R')
				info[i][j] = 'G';
		}
}
int main(void)
{

	int i,j;
	char enter;

	init();
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%c", &enter);
		for (j = 0; j < n; j++)
		{
			scanf("%c", &info[i][j]);
		}
	}
	///////////////색약이 아닌사람이 보는 구역의 수 구하기
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (visited[i][j] == 0)
			{
				dfs(i, j);
				colorcnt++;
			}
		}
	}
	///////////////////색약인 사람이 보는 구역의 수 구하기
	init();
	changeforweak();//info함수를 색약인 사람이 보는것처럼 바꾸어줌.
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (visited[i][j] == 0)
			{
				dfs(i, j);
				colorweakcnt++;
			}
		}
	}
	printf("%d %d", colorcnt, colorweakcnt);
}
