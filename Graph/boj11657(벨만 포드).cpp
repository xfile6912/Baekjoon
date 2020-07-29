#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;
vector<vector<int> > path(501, vector<int>( 501, 0));
vector<int> visited(501, 0);//경로상에 존재하는지 판단하기 위해서
int nCity;
int mBus;
int from, to, cost;
void dfs(int v) {
	visited[v] = 1;
	for (int i = 1; i <= nCity; i++)
	{
		if (path[v][i] == 1 && visited[i] == 0)
			dfs(i);
	}
}//dfs를 통하여 경로 탐색
int main(void)
{

	scanf("%d", &nCity);
	vector<long long> totalCost(nCity+1, 2147483647);
	totalCost[1] = 0;//시작점의 코스트를 0으로 설정;
	scanf("%d", &mBus);
	vector<vector<int> > busInfo(mBus, vector<int>(3, 0));
	for (int i = 0; i < mBus; i++)
	{
		scanf("%d %d %d", &busInfo[i][0], &busInfo[i][1], &busInfo[i][2]);
		path[busInfo[i][0]][busInfo[i][1]] = 1;
	}
	int i, j;
	dfs(1);//모든 정점을 경로에 있는지 없는지 검사, visited가 1이면 경로에 있는 정점임
	for (j = 0; j < nCity; j++)//각 간선을 정점만큼 검사하여 벨만포드
	{
		for (i = 0; i < mBus; i++)
		{
			if (busInfo[i][2] + totalCost[busInfo[i][0]] < totalCost[busInfo[i][1]])
			{
				totalCost[busInfo[i][1]] = busInfo[i][2] + totalCost[busInfo[i][0]];
			}
		}
	}
	int flag = 0;
	for (i = 0; i < mBus; i++)//음수 사이클이 발생하는지 검사.
	{
		if (busInfo[i][2] + totalCost[busInfo[i][0]] < totalCost[busInfo[i][1]] && visited[busInfo[i][1]]==1)//경로상에 있고 음수사이클이 존재하면
		{
			printf("-1\n");//음수 사이클이 발생하는 경우.
			return 0;
		}
	}
	for (i = 2; i <= nCity; i++)
	{
		if (visited[i]==0)//경로가 없는 경우
			printf("%d\n", -1);
		else//경로가 있는 경우
			printf("%d\n", totalCost[i]);
	}
}
