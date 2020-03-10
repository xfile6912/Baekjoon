#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include <set>
using namespace std;

int n;
int w[10001];//가중치
vector<int> graph[10001];//트리를 나타내는 그래프
vector<int> answer;
int cache[10001][2];//메모제이션값 저장
int dfs(int v, int flag, int from)//flag가 0이면 해당 됨 from은 해당 정점이 어느 정점으로부터 왔는지 표시(visited와 같은 역할)
{
	int& ret = cache[v][flag];

	if (ret != -1)
		return ret;

	ret = 0;

	if (flag == 1)//만약 현재정점이 최대독립집합에 해당된다면 현재정점과 연결된 정점들은 해당되면 안된다.
	{
		for (int i = 0; i < graph[v].size(); i++)
		{
			if (graph[v][i] != from)//이미 방문한 정점이 아니라면
			{
				ret += dfs(graph[v][i], 0, v);
			}
		}
		ret += w[v];//v라는 정점이 최대독립집합에 해당되므로 더해줘야한다.
	}
	else//만약 현재정점이 최대 독립집합이 아니라면 현재정점과 연결된 정점들은 최대독립집합일수도 있고 아닐수도 있다.
	{
		for (int i = 0; i < graph[v].size(); i++)
		{
			if (graph[v][i] != from)
			{
				ret += max(dfs(graph[v][i], 0, v), dfs(graph[v][i], 1, v));
			}
		}
	}
	return ret;

}

void tracking(int v, int flag, int from)//집합의 멤버 구하기위한 함수
{
	if (flag == 1)//현재 정점이 최대 독립집합에 해당되면 이정점과 연결된 정점들은 최대 독립집합이 아니어야한다.
	{
		answer.push_back(v);
		for (int i = 0; i < graph[v].size(); i++)
		{
			if (graph[v][i] != from)
			{
				tracking(graph[v][i], 0, v);
			}
		}
	}
	else//만약 현재정점이 최대 독립집합이 아니라면 현재정점과 연결된 정점들은 최대독립집합일수도 있고 아닐수도 있다.
	{
		for (int i = 0; i < graph[v].size(); i++)
		{
			if (graph[v][i] != from)
			{
				if (cache[graph[v][i]][0] > cache[graph[v][i]][1])//만약 연결된 정점이 최대독립집합이 아닐때의 값이 더 크다면 연결된 정점은 최대 독립집합이 아니다.
				{
					tracking(graph[v][i], 0, v);
				}
				else//만약 연결된 정점이 최대독립집합일때 값이 더 크다면 연결된 정점은 최대 독립집합이다.
				{
					tracking(graph[v][i], 1, v);
				}
			}
		}
	}
}
int main(void)
{
	int v1, v2;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &w[i]);
		cache[i][1] = -1;//메모제이션 배열 초기화;
		cache[i][0] = -1;
	}
	for (int i = 1; i < n; i++)
	{
		scanf("%d %d", &v1, &v2);
		graph[v1].push_back(v2);//v1정점에 v2를 이어줌
		graph[v2].push_back(v1);//v2정점에 v1을 이어줌
	}
	//두가지 경우로 나뉨(해당정점이 최대독립집합에 해당되는경우, 아닌경우)
	printf("%d\n", max(dfs(1, 1,-1), dfs(1, 0,-1)));
	if (cache[1][0] > cache[1][1])
	{
		tracking(1, 0, -1);
	}
	else
	{
		tracking(1, 1, -1);
	}
	sort(answer.begin(),answer.end());//트래킹해서 찾은 정점들을 오름차순으로 정렬
	for (int i = 0; i < answer.size(); i++)
		printf("%d ", answer[i]);

}
