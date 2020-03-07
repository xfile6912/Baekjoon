#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
using namespace std;

vector<int> answer(100001);
vector<vector<int> > graph(100001);
void dfs(int root)
{
	int i;
	for (i = 0; i < graph[root].size(); i++)
	{
		if (answer[graph[root][i]] == 0)
		{
			answer[graph[root][i]] = root;//만약에 검사하는 정점의 answer값이 0이면 이 노드는 방문하지 않은 노드이고
			dfs(graph[root][i]);//방문하지 않은 노드는 루트의 자식노드이다, 따라서 자식노드에 부모를 초기화해주고 dfs;
		}
	}
}


int main(void)
{
	int n;
	scanf("%d", &n);
	int i;

	int v1, v2;
	for (i = 1; i < n; i++)
	{
		scanf("%d %d", &v1, &v2);//정점 v1, v2사이에 간선이 있다.
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);//그래프에 간선을 넣어줌;
	}
	answer[1] = -1;//1번노드는 트리의 루트임;
	dfs(1);//트리를 루트부터 순회함
	for (i = 2; i <= n; i++)
	{
		printf("%d\n", answer[i]);
	}
}
