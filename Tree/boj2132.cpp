#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include <set>
using namespace std;

int n;
int w[10001];//정점 i에 따른 열매의개수
vector<int> max1storage(10001, 0);//각 정점에 대해 max1 저장하는 배열
vector<int> max2storage(10001, 0);//각 정점에 대해 max2 저장하는 배열
vector<int> maxstorage(10001, 0);//각 정점에 대해 maxvalue 저장하는 배열
vector<int> wfrom(10001, -1);//각 정점에 대해 어디서 왔는지 저장하는 배열
vector<int> graph[10001];//트리를 나타내는 그래프
int maxvalue = 0;
int dfs(int v, int from)//dfs는 v를 루트로 하는 트리에서 가지를 골라 가지 끝까지 내려갔을 때 최대 열매 수 반환
{
	wfrom[v] = from;
	int max1 = 0;//가지들 중 하나를 골라 가지 끝까지 갔을때 열매들의 가중치 가장 큰값 저장
	int max2 = 0;//두번째로 큰값;
	priority_queue<int> answer;
	for (int i = 0; i < graph[v].size(); i++)
	{
		if (graph[v][i] != from)//이미 방문한 정점이 아니라면
		{
			answer.push(dfs(graph[v][i], v));
		}
	}
	if (answer.size() == 0)
	{

	}
	else if (answer.size() == 1)
	{
		max1 = answer.top();
	}
	else
	{
		max1 = answer.top();
		answer.pop();
		max2 = answer.top();
	}
	max1storage[v] = max1;
	max2storage[v] = max2;
	maxstorage[v] = max1 + max2 + w[v];
	if (max1 + max2 + w[v] > maxvalue)
	{
		maxvalue = max1 + max2 + w[v];
	}
	return max1 + w[v];

}
vector<int> findindex;
vector<int> check(10001, 0);
int tracking(int v, int from, int max, int sum,int depth)//이동시작 정점 찾기위해 트래킹
{
	int flag = 0;
	for (int i = 0; i < graph[v].size(); i++)
	{
		if (graph[v][i] != from && check[graph[v][i]] != 1)//이미 방문한 정점이 아니고, max1의 경로가 아니라면
		{
			if (tracking(graph[v][i], v, max, sum + w[graph[v][i]], depth + 1) == 1)
			{
				if (depth == 0 && check[graph[v][i]] == 0)//v의 자식노드인 [v][i]의 경로에서 max1을 찾았다면, max2를 찾을때 해당경로는 검색안해야됨.
				{
					check[graph[v][i]] = 1;
				}
				flag = 1;
			}
		}
		else
			check[graph[v][i]] = 0;
	}


	if (max == sum)
	{
		findindex.push_back(v);
		return 1;
	}
	if (flag == 1)
		return 1;
	return 0;
}

int main(void)
{
	int v1, v2;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &w[i]);
	}
	for (int i = 1; i < n; i++)
	{
		scanf("%d %d", &v1, &v2);
		graph[v1].push_back(v2);//v1정점에 v2를 이어줌
		graph[v2].push_back(v1);//v2정점에 v1을 이어줌
	}
	dfs(1, -1);
	printf("%d", maxvalue);
	for (int i = 1; i <= n; i++)
	{
		if (maxvalue == maxstorage[i])
		{
			tracking(i, wfrom[i] ,max1storage[i], 0,0);//max1의 경로에서 찾아줌.
			tracking(i, wfrom[i], max2storage[i], 0,0);//max2의 경로에서 찾아줌.
		}
	}
	sort(findindex.begin(), findindex.end());
	printf(" %d", findindex[0]);
}
