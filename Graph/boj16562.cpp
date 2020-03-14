#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;



vector<int> graph[10001];//친구관계 표현
int student[10001];//i번째 학생이 친구비로 원하는 돈;
vector<int> isfriend(10001, 0);//친구이면 1임;
priority_queue<int, vector<int>, greater<int> > cost;//해당 친구집단에서 가장 비용이 적게드는 사람을 찾기 위해서
void dfs(int x)
{
	int i;
	isfriend[x] = 1;
	cost.push(student[x]);//cost에는 해당 친구집단에서 드는 비용이 작은순서대로 들어가있음
	for (i = 0; i < graph[x].size(); i++)
	{
		if (isfriend[graph[x][i]] == 0)
		{
			dfs(graph[x][i]);
		}
	}
}

 int main(void)
{
	int n, m;
	int k;
	int answer=0;
	int i;
	int v1, v2;
	scanf("%d %d %d", &n, &m, &k);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &student[i]);
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &v1, &v2);
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	for (i = 1; i <= n; i++)
	{
		if (isfriend[i] == 0)
		{
			dfs(i);
			answer+=cost.top();
			while (!cost.empty())
				cost.pop();
		}
	}
	if (answer <= k)
		printf("%d", answer);
	else
		printf("Oh no");
}
