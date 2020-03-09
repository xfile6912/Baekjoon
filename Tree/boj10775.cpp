#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <cmath>
using namespace std;

int gateNum;//게이트의 수
int planeNum;//비행기의 수
vector<int> parent(100001,-1);

int find(int gate)
{
	if (parent[gate] == -1)//해당게이트는 아직 비어있음;
		return gate;
	else
		return parent[gate]=find(parent[gate]);
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	parent[x] = y;
}

int main(void)
{
	int temp;//비행기 정보 임시 저장
	int gate;//해당 비행기를 넣을수 있는 게이트
	int answer=0;
	scanf("%d", &gateNum);
	scanf("%d", &planeNum);
	for (int i = 1; i <= planeNum; i++)
	{
		scanf("%d", &temp);
		gate = find(temp);
		if (gate == 0)
			break;
		answer++;
		unite(gate, gate-1);

	}
	printf("%d\n", answer);
}
