#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;
int n, k, s;
int dfs(int v, int end, vector<vector<int> > &graph, vector<int> &visited)
{
	visited[v] = 1;
	if (v == end)
		return 1;
	int result = 0;
	for (int i = 0; i < graph[v].size(); i++)
	{
		if (visited[graph[v][i]] == 0)
		{
			if (dfs(graph[v][i], end, graph, visited))
				return 1;
		}
	}
	return 0;
}
void initvisited(vector<int>& visited)
{
	for (int i = 1; i <= n; i++)
		visited[i] = 0;
}
int main(void)
{

	int i, j;
	int before, after;
	scanf("%d %d", &n, &k);
	vector<vector<int> > graph(n + 1);
	vector<int> visited(n + 1, 0);
	for (i = 0; i < k; i++)
	{
		scanf("%d %d", &before, &after);
		graph[before].push_back(after);
	}
	scanf("%d", &s);
	for (i = 0; i < s; i++)
	{
		int flag = 0;
		scanf("%d %d", &before, &after);
		initvisited(visited);
		if (dfs(before, after, graph, visited))
			flag = -1;
		initvisited(visited);
		if (dfs(after, before, graph, visited))
			flag = 1;
		printf("%d\n", flag);
	}
}
