#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>

using namespace std;
int n, m;

void dfs(int v, vector<vector<int> >& map,vector<int>& visited)
{
	visited[v] = 1;
	int i;
	for (i = 0; i < n; i++)
	{
		if (map[v][i] == 1 && visited[i] == 0)
			dfs(i, map, visited);
	}
}


int main(void)
{

	scanf("%d %d", &n, &m);

	vector<vector<int> > map(n, vector<int>(n, 0));
	vector<int> visited(n, 0);
	vector<int> confirm(m, 0);
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d", &confirm[i]);
		confirm[i] -= 1;//1씩 빼줌으로써 map에서의 index값과 맞추어줌.
	}
	dfs(confirm[0],map, visited);//첫 여행지부터 dfs해서 갈수 있는 곳을 모두 체크
	int flag = 1;
	for (i = 0; i < m; i++)
	{
		if (visited[confirm[i]] == 0)//visited[confirm[i]]가 0이면 첫여행지를 통해서 갈 수 없는 경우이므로 NO인 경우. 
		{
			flag = 0;
			break;
		}
	}
	if (flag == 1)
		printf("YES\n");
	else
		printf("NO\n");
}
