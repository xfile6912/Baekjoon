#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
using namespace std;

char map[10000][500];
char visited[10000][500];
int r, c;

void init()
{
	int i, j;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
			visited[i][j] = 0;
	}
}
int dfs(int y, int x) {
	visited[y][x] = 1;
	if (x == c-1)
		return 1;
	if (y - 1 >= 0 && visited[y - 1][x + 1] == 0 && map[y - 1][x + 1] != 'x')//대각선 위쪽으로 가는 경우
	{
		if (dfs(y - 1, x + 1))
			return 1;//대각선 위쪽으로 가서 빵집에 도착 하였으면 더이상 경로를 찾지 않는다.

	}
	if (visited[y][x + 1] == 0 && map[y][x + 1] != 'x')//오른쪽으로가는경우
	{
		if (dfs(y, x + 1))//오른쪽으로 가서 빵집에 도착 하였으면 더이상 경로를 찾지 않는다.
			return 1;
	}
	if (y + 1 < r && visited[y + 1][x + 1] == 0 && map[y + 1][x + 1] != 'x')//대각선 아래쪽으로 가는경우
		if (dfs(y + 1, x + 1))
			return 1;
	return 0;//빵집으로 가는 경로가 없으면 0을 리턴
	
}

int main(void)
{


	scanf("%d %d", &r, &c);
	char enter;
	int i, j;
	int result = 0;
	init();
	for (i = 0; i < r; i++)
	{
		scanf("%c", &enter);
		for (j = 0; j < c; j++)
		{
			scanf("%c", &map[i][j]);
		}
	}
	for (i = 0; i < r; i++)
	{
		result+=dfs(i, 0);
	}
	printf("%d", result);
}
