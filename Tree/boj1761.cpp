#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include <set>
using namespace std;

int n, m;

typedef struct node {
	int v;
	int length;
}NODE;
vector<NODE> graph[40001];
int parent[40001][2];//[0]에는 부모 정점이/ [1]에는 부모정점과의 거리;
int depth[40001];//각노드의 루트로부터 깊이를 담고있음
vector<int> check(40001,0);
void maketree(int x, int from)
{
	int i;
	NODE node;
	parent[x][0] = from;
	for (i = 0; i < graph[x].size(); i++)
	{
		if (graph[x][i].v != from)
		{
			depth[graph[x][i].v] = depth[x] + 1;
			parent[graph[x][i].v][1] = graph[x][i].length;
			maketree(graph[x][i].v, x);
		}
	}
}

int commonancestor(int x, int y)//공통조상을 찾아줌;
{
	if (depth[x] < depth[y])//깊이를 맞춰줌;
	{
		while (depth[x]!=depth[y])
		{
			y = parent[y][0];
		}
	}
	else if(depth[x]>depth[y])
	{
		while (depth[x] != depth[y])
		{
			x = parent[x][0];
		}
	}
	while (x != y)
	{
		x = parent[x][0];
		y = parent[y][0];
	}
	return x;
}
int solve(int x, int y)
{
	int result = 0;
	int ancestor = commonancestor(x, y);
	int temp = x;
	while (temp != ancestor)
	{
		result += parent[temp][1];//부모정점과의 거리를 더해줌;
		temp = parent[temp][0];
	}
	 temp = y;
	while (temp != ancestor)
	{
		result += parent[#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include <set>
using namespace std;

int n, m;

typedef struct node {
	int v;
	int length;
}NODE;
vector<NODE> graph[40001];
int parent[40001][2];//[0]에는 부모 정점이/ [1]에는 부모정점과의 거리;
int depth[40001];//각노드의 루트로부터 깊이를 담고있음
vector<int> check(40001,0);
void maketree(int x, int from)
{
	int i;
	NODE node;
	parent[x][0] = from;
	for (i = 0; i < graph[x].size(); i++)
	{
		if (graph[x][i].v != from)
		{
			depth[graph[x][i].v] = depth[x] + 1;
			parent[graph[x][i].v][1] = graph[x][i].length;
			maketree(graph[x][i].v, x);
		}
	}
}

int commonancestor(int x, int y)//공통조상을 찾아줌;
{
	if (depth[x] < depth[y])//깊이를 맞춰줌;
	{
		while (depth[x]!=depth[y])
		{
			y = parent[y][0];
		}
	}
	else if(depth[x]>depth[y])
	{
		while (depth[x] != depth[y])
		{
			x = parent[x][0];
		}
	}
	while (x != y)
	{
		x = parent[x][0];
		y = parent[y][0];
	}
	return x;
}
int solve(int x, int y)
{
	int result = 0;
	int ancestor = commonancestor(x, y);
	int temp = x;
	while (temp != ancestor)
	{
		result += parent[temp][1];//부모정점과의 거리를 더해줌;
		temp = parent[temp][0];
	}
	 temp = y;
	while (temp != ancestor)
	{
		result += parent[temp][1];//부모정점과의 거리를 더해줌;
		temp = parent[temp][0];
	}
	return result;
}
int main(void)
{
	int i;
	int v1, v2, length;
	scanf("%d", &n);
	for (i = 0; i < n - 1; i++)//트리 만듬;
	{
		scanf("%d %d %d", &v1, &v2, &length);
		NODE temp;
		temp.v = v2;
		temp.length = length;
		graph[v1].push_back(temp);
		temp.v = v1;
		temp.length = length;
		graph[v2].push_back(temp);
	}
	depth[1] = 0;
	maketree(1, -1);//1번을 루트로해서 트리 만듦
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &v1, &v2);
		printf("%d\n",solve(v1, v2));
	}
}temp][1];//부모정점과의 거리를 더해줌;
		temp = parent[temp][0];
	}
	return result;
}
int main(void)
{
	int i;
	int v1, v2, length;
	scanf("%d", &n);
	for (i = 0; i < n - 1; i++)//트리 만듬;
	{
		scanf("%d %d %d", &v1, &v2, &length);
		NODE temp;
		temp.v = v2;
		temp.length = length;
		graph[v1].push_back(temp);
		temp.v = v1;
		temp.length = length;
		graph[v2].push_back(temp);
	}
	depth[1] = 0;
	maketree(1, -1);//1번을 루트로해서 트리 만듦
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &v1, &v2);
		printf("%d\n",solve(v1, v2));
	}
}
