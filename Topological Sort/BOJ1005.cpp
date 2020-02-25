#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
using namespace std;
int w;
int dfs(int x,vector<int>& from, vector<int> &building, vector<vector<int> >& info, vector<int> &cache)
{
	if (x == w)
		return building[w];


	int& ret = cache[x];
	if (cache[x] != -1)
		return ret;

	ret = 0;
	int i;
	int temp;
	for (i = 0; i < info[x].size(); i++)
	{
		temp = dfs(info[x][i], from, building, info, cache);
		if(temp!=0)
			ret = max(ret, temp+building[x]);
	}
	return ret;
}


int main(void)
{
	int t;
	int n, k;
	int rule[2];
	int i, j,p;

	scanf("%d", &t);
	for (p = 0; p < t; p++)
	{
		scanf("%d %d", &n, &k);
		queue<int> q;
		vector<int> from(n+1, 0);//자기 자신으로 들어오는 간선 수 저장
		vector<int> building(n + 1, 0);//빌딩을 짓는데 걸리는시간
		vector<vector<int> > info(n+1);//그래프
		vector<vector<int> > fromgraph(n + 1);//누구로부터 왔는지 표현해주는 그래프
		vector<int> result(n + 1, 0);//i번째 건물을 짓기까지 걸리는 시간

		for (i = 1; i <= n; i++)
		{
			scanf("%d", &building[i]);
		}
		for (i = 0; i < k; i++)
		{
			scanf("%d %d", &rule[0], &rule[1]);
			info[rule[0]].push_back(rule[1]);//rule[0]에서 rule[1]으로 가는 길이 존재함.
			fromgraph[rule[1]].push_back(rule[0]);
			from[rule[1]]++;
		}
		scanf("%d", &w);

		for (i = 1; i <= n; i++)
		{
			if (from[i] == 0)
				q.push(i);
		}
		int x;
		for (i = 1; i <= n; i++)
		{
			x=q.front();
			if (fromgraph[x].size() == 0)
			{
				result[x] = building[x];//x가 시작점이라면 건물 x를 짓기 위해서는 building[x]만큼의 시간만 필요함.
			}
			for (j = 0; j < fromgraph[x].size(); j++)
			{
				result[x] = max(result[x], result[fromgraph[x][j]]+building[x]);//x가 시작점이 아니라면 건물x를 짓는데 걸리는 시간은
			}//건물 x를 짓기위해 지었던 건물들 중에서 시간이 가장 많이 필요한 건물 값에 빌딩 x를 짓는데 걸리는 시간을 더해준다.
			q.pop();
			for (j = 0; j < info[x].size(); j++)
			{
				if (--from[info[x][j]] == 0)//x와 연결된 간선을 모두 제거해주고 이로인해 연결되어 있던 vertex의 from이 0이된다면 q에 넣어줌.
					q.push(info[x][j]);//큐에추가해줌.
			}
		}
		printf("%d\n", result[w]);
	}
	

}
