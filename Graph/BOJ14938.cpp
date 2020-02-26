#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
using namespace std;
vector<int> visited(100, 0);
int dfs(int x, int m, vector<vector<int> > road, vector<int> item)
{
	int i;
	int ret = 0;
	for (i = 0; i < road[x].size(); i++)
	{
		if (road[x][i] != 0 && m - road[x][i] >= 0)//i로 가는 길이 있고 남은 수색범위로 갈수 있을 때에
		{
			if (visited[i]== 1)//이미 방문했던 지역이면 아이템이 없으므로
			{
				ret += dfs(i, m - road[x][i], road, item);
			}
			else//방문 안 한 지역이면 아이템이 있음
			{
				visited[i] = 1;
				ret += dfs(i, m - road[x][i], road, item) + item[i];
			}
		}
	}
	return ret;
}


int main(void)
{
	int n, m, r;
	scanf("%d %d %d", &n, &m, &r);
	vector<int> item(n, 0);
	vector<vector<int> > road(n, vector<int>(n, 0));
	int v1, v2, distance;
	int maxvalue=0;
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &item[i]);
	}
	for (i = 0; i < r; i++)
	{//그래프 정보를 road 인접행렬에 저장
		scanf("%d %d %d", &v1, &v2, &distance);
		road[v1 - 1][v2 - 1] = distance;
		road[v2 - 1][v1 - 1] = distance;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			visited[j] = 0;
		visited[i] = 1;
		maxvalue = max(maxvalue, dfs(i, m,road, item)+item[i]);
	}
	printf("%d", maxvalue);
}
