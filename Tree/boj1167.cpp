#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
using namespace std;

typedef struct node {
	int vertex;
	int length;
}NODE;

vector<NODE> graph[100001];
vector<int> visited(100001);

void initvisited(int n)
{
	int i;
	for (i = 1; i <= n; i++)
		visited[i] = 0;
}
int maxvalue=0;

int dfs(int x)
{
	int i;
	int max1=0;
	int max2=0;
	vector<int> a;
	for (i = 0; i < graph[x].size(); i++)
	{
		if (visited[graph[x][i].vertex] == 0)
		{
			visited[graph[x][i].vertex] = 1;
			int temp=dfs(graph[x][i].vertex)+graph[x][i].length;
			a.push_back(temp);
		}
	}
	sort(a.begin(),a.end());
	if (a.size() > 1)
	{
		max1 = a[a.size() - 1];
		max2 = a[a.size() - 2];
	}
	else if (a.size() == 1)
		max1 = a[a.size() - 1];
	if (max1 + max2  > maxvalue)
		maxvalue = max1 + max2;
	return max1;
}

int main(void)
{
	int n;
	int v1, v2, length;
	NODE tree;
	scanf("%d", &n);
	int i;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &v1);//간선;
		while (1)
		{
			scanf("%d", &v2);
			if (v2 == -1)
				break;
			scanf("%d", &length);
			tree.vertex = v2;
			tree.length = length;
			graph[v1].push_back(tree);
		}
	}
	initvisited(n);
	visited[1] = 1;
	int temp= dfs(1);
	printf("%d", maxvalue);
}
