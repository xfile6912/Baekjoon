#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int n;//마을의 수;
int people[10001];//마을 주민의수;
vector<int> graph[10001];//트리
vector<int> visited(10001, 0);
vector<vector<int> > dp(10001, vector<int>(2, -1));
int dfs(int x, int great)//great이 1이면 우수마을//x는 현재마을
{
	int& ret = dp[x][great];

	if (ret != -1)
		return ret;
	visited[x] = 1;
	ret=0;
	if (great == 1)
	{
		for (int i = 0; i < graph[x].size(); i++)
		{
			if (visited[graph[x][i]] == 0)
			{
				ret += dfs(graph[x][i], 0);//현재 마을이 우수마을이면 인접한 마을들은 다 우수마을이 아니어야함;
			}
		}
		ret += people[x];
	}
	else
	{
		for (int i = 0; i < graph[x].size(); i++)
		{
			if (visited[graph[x][i]] == 0)
			{
				ret += max(dfs(graph[x][i], 0), dfs(graph[x][i], 1));//현재마을이 우수마을이 아니면 인접한 마을은 우수마을일수도 있고 우수마을이 아닐수도 있음
			}
		}
	}
	visited[x] = 0;
	return ret;
}



int main(void)
{
	int i, j;
	int v1, v2;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)//각 마을 주민수 입력받음
	{
		scanf("%d", &people[i]);
	}
	for (i = 1; i < n; i++)
	{
		scanf("%d %d", &v1, &v2);
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	int temp1, temp2;
	temp1 = dfs(1, 0);
	temp2 = dfs(1, 1);
	if (temp1 > temp2)
		printf("%d", temp1);
	else
		printf("%d", temp2);
}
