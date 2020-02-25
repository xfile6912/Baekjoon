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
	int result;

	scanf("%d", &t);
	for (p = 0; p < t; p++)
	{
		scanf("%d %d", &n, &k);
		result = 0;
		vector<int> from(n+1, 0);//자기 자신으로 들어오는 간선 수 저장
		vector<int> building(n + 1, 0);
		vector<vector<int> > info(n+1);
		vector<int> cache(n+1, -1);
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &building[i]);
		}
		for (i = 0; i < k; i++)
		{
			scanf("%d %d", &rule[0], &rule[1]);
			info[rule[0]].push_back(rule[1]);//rule[0]에서 rule[1]으로 가는 길이 존재함.
			from[rule[1]]++;
		}
		scanf("%d", &w);
		for (i = 1; i <= n; i++)
		{

			if (from[i] == 0)
				result = max(result, dfs(i,from, building, info,cache));
		}
		printf("%d\n", result);


		/*for (i =1; i <= n; i++)
		{
			if (from[i] == 0)
				q.push(i);
		}
		for (i = 1; i <= n; i++)
		{
			int x = q.front();
			result+=building[x];
			q.pop();
			for (j = 0; j < info[x].size(); j++)
			{
				from[info[x][j]]--;//x와 연결되어 있는 모든 간선 제거;
				if (from[info[x][j]] == 0)
				{
					q.push(info[x][j]);
				}
			}
		}*/

	}
	

}
