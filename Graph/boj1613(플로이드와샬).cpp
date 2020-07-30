#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

int main(void)
{
	int n, k, s;
	int i, j, x;
	int before, after;
	scanf("%d %d", &n, &k);
	vector<vector<int> > graph(n + 1, vector<int> (n+1, 987654321));
	for (i = 0; i < k; i++)
	{
		scanf("%d %d", &before, &after);
		graph[before][after]=1;
	}
	for (i = 1; i <= n; i++)
	{
		graph[i][i] = 0;//자기 자신으로 가는 사건은 0임.
	}
	for (x = 1; x <= n; x++)//플로이드 와샬알고리즘.
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (graph[i][j] > graph[i][x] + graph[x][j])
					graph[i][j] = graph[i][x] + graph[x][j];
			}
		}
	}
	scanf("%d", &s);
	for (i = 0; i < s; i++)
	{
		scanf("%d %d", &before, &after);
		int flag = 0;//알수없음
		if (graph[before][after] < 987654321)//먼저일어남
			flag = -1;
		else if (graph[after][before] < 987654321)//나중에 일어남
			flag = 1;
		printf("%d\n", flag);
	}
}
