#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
using namespace std;

vector<int> graph[50];

int leaf = 0;
int deleted;
void dfs(int root)
{
	int i;
	for (i = 0; i < graph[root].size(); i++)
	{
		if(graph[root][i]!=deleted)//해당노드가 딜리트된 노드라면 방문할 필요가 없음
			dfs(graph[root][i]);
	}
	if (graph[root].size() == 1 && graph[root][0] == deleted)//만약에 해당노드의 자식이 딜리트 되었는데 해당노드의 자식이 한명뿐이었다면
		leaf++;//이는 리프노드가 된다.
	if (graph[root].size() == 0)//만약에 해당 노드로부터 연결된 노드가 아무것도 없다면 이는 리프노드이다.
		leaf++;
}

int main(void)
{
	int n;
	int root;
	scanf("%d", &n);
	vector<int> info(n, 0);
	int i;
	for (i = 0; i < n; i++)
		scanf("%d", &info[i]);
	scanf("%d", &deleted);
	for (i = 0; i < n; i++)
	{
		if (info[i] == -1)//-1이면 노드;
		{
			root = i;
		}
		else
		{
			graph[info[i]].push_back(i);//트리를 그래프로 만들어줌
		}
	}
	if(root!=deleted)
		dfs(root);
	printf("%d",leaf);
}
