#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include <set>
using namespace std;

int n, q;
vector<int> parent(200001, -1);
vector<int> revers(200001, -1);
int main(void)
{
	int i;
	int order;
	int a, b;
	scanf("%d %d", &n, &q);
	for (i = 2; i <= n; i++)
		scanf("%d", &parent[i]);
	vector<vector<int> > cache(n - 1 + q, vector<int> (3,0));//[i][0]에는 order, [i][1]에는 a, [i][2]에는 b가 들어간다.
	for (i = 0; i < n-1+q; i++)
	{
		scanf("%d", &order);
		if (order == 0)//(1)의 경우
		{
			scanf("%d", &a);
			cache[i][0] = 0;
			cache[i][1] = a;//a는 삭제하려는 간선
		}
		else//(2)의 경우
		{
			scanf("%d %d", &a, &b);
			cache[i][0] = 1;
			cache[i][1] = a;
			cache[i][2] = b;

		}
	}
	vector<int> answer;
	for (i = n - 2 + q; i >= 0; i--)//뒤에서부터 거꾸로 jointset을 만들면서 시작(disjointset을 경로를 압축해서 만들어 루트 검색을 빠르게 해주기 위해)
	{
		int a, b;
		if (cache[i][0] == 0)
		{
			a = cache[i][1];
			b = parent[a];
			while (revers[a] >= 0)//루트찾아줌;
			{
				a = revers[a];
			}
			while (revers[b] >= 0)//루트 찾아줌;
			{
				b = revers[b];
			}
			if (revers[a] < revers[b])//경로를 압축해주기 위해 만약에 a가 속해있는 집합원소 수가 b가 속해있는 집합원소보다많다면 b 집합의 루트를 a집합의 루트랑 연결해줌;
			{
				revers[a] += revers[b];//최종 루트에는 해당 루트가 속한 집합 원소의 수가  (-)붙혀 저장되어있음
				revers[b] = a;
			}
			else
			{
				revers[b] += revers[a];
				revers[a] = b;
			}
		}
		else
		{
			a = cache[i][1];
			b = cache[i][2];
			while (revers[a] >= 0)//루트찾아줌;
			{
				a = revers[a];
			}
			while (revers[b] >= 0)//루트 찾아줌;
			{
				b = revers[b];
			}
			if (a == b)
				answer.push_back(1);
			else
				answer.push_back(0);

		}
	}
	for (i = answer.size() - 1; i >= 0; i--)
	{
		if (answer[i] == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}

}
