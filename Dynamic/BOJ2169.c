#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

long long minvalue = -10000000000001;
long long info[1000][1000];
long long dp[1000][1000][3];
int visited[1000][1000];
int n, m;

long long dfs(int y, int x, int dir)
{
	long long temp;
	long long& ret = dp[y][x][dir];
	if (y == n - 1 && x == m - 1)
	{
		return info[y][x];
	}

	if (ret != minvalue)
	{

		return ret;
	}
	ret = minvalue;

	if (x - 1 >= 0 && visited[y][x - 1] == -1 && y != n - 1)//왼쪽으로 움직이는경우
	{
		visited[y][x - 1] = 1;//방문 했던 곳을 다시 가지 않기 위해서

		ret = max(ret, dfs(y, x - 1,1));
		visited[y][x - 1] = -1;

	}
	if (x + 1 < m && visited[y][x + 1] == -1)//오른쪽으로 움직이는 경우
	{
		visited[y][x + 1] = 1;//방문 했던 곳을 다시 가지 않기 위해서
		ret = max(ret, dfs(y, x + 1,0));
		visited[y][x + 1] = -1;//순회를 마쳤으므로 다른 경우를 위해서 다시 방문 안함으로 바꿔 줌.

	}
	if (y + 1 < n && visited[y + 1][x] == -1)//밑으로 움직이는 경우
	{
		visited[y + 1][x] = 1;//방문 했던 곳을 다시 가지 않기 위해서
		ret = max(ret, dfs(y + 1, x,2));
		visited[y + 1][x] = -1;

	}
	if (ret != minvalue)
		ret = ret + info[y][x];
	return ret;
}

int main(void)
{
	scanf("%d %d", &n, &m);
	int i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%lld", &info[i][j]);
			dp[i][j][0] = minvalue;
			dp[i][j][1] = minvalue;
			dp[i][j][2] = minvalue;
			visited[i][j] = -1;
		}
	}
	visited[0][0] = 1;
	printf("%lld", dfs(0, 0,0));

}
