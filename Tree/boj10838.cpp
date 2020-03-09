#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include <set>
using namespace std;
int parent[100000];
int color[100000];
int check[100000];
int n, k;
void maketree(int n)
{
	parent[0] = -1;
	for (int i = 1; i < n; i++)
	{
		parent[i] = 0;
		color[i] = 0;
	}
}

void paint(int a, int b, int c)
{
	////공통조상찾기시작
	int temp = a;
	int ancestor;
	int cnt = 0;
	while (cnt<=1000)
	{
		check[temp] = 1;
		temp = parent[temp];
		if (temp == -1)
			break;
		cnt++;
	}
	temp = b;
	while (1)
	{
		if (check[temp] == 1)
		{
			ancestor = temp;
			break;
		}
		temp = parent[temp];
	}
	/////////공통 조상 찾음;

	////////공통조상까지 컬러 바꾸어주기 시작
	temp = a;
	while (temp!=ancestor)
	{
		color[temp] = c;
		temp = temp[parent];
	}
	temp = b;
	while (temp != ancestor)
	{
		color[temp] = c;
		temp = parent[temp];
	}
	///////////////공통조상까지 컬러 바꾸어줌

	//////////////check배열 원래대로 돌려주기시작
	temp = a;
	cnt = 0;
	while (cnt<=1000)
	{
		check[temp] = 0;
		temp = parent[temp];
		if (temp == -1)
			break;
		cnt++;
	}
	//////////////////check배열 원래대로 돌려줌
}
void move(int a, int b)
{
	parent[a] = b;
}
int count(int a, int b)
{
	set<int> answer;
	//////////공통조상찾기 시작
	int temp = a;
	int ancestor;
	int cnt = 0;
	while (cnt<=1000)
	{
		check[temp] = 1;
		temp = parent[temp];
		if (temp == -1)
			break;
		cnt++;
	}
	temp = b;
	while (1)
	{
		if (check[temp] == 1)
		{
			ancestor = temp;
			break;
		}
		temp = parent[temp];
	}
	/////////////공통조상찾음

	////////////공통조상까지의 컬러를 셋에 넣어주기시작
	temp = a;
	while (temp != ancestor)
	{
		answer.insert(color[temp]);
		temp = temp[parent];
	}
	temp = b;
	while (temp != ancestor)
	{
		answer.insert(color[temp]);
		temp = parent[temp];
	}
	/////////////공통조상까지의 컬러를 셋에 넣어줌;


	/////////////check배열 원래대로 돌려주기 시작
	temp = a;
	cnt = 0;
	while (cnt<=1000)
	{
		check[temp] = 0;
		temp = parent[temp];
		if (temp == -1)
			break;
		cnt++;
	}
	/////////////check배열 원래대로 돌려줌

	return answer.size();
}
int main(void)
{
	int order;//명령(1:paint, 2:move, 3:count)
	int a, b;
	int color;
	scanf("%d %d", &n, &k);
	maketree(n);//첫 트리를 만듦
	for (int i = 0; i < n; i++)
		check[i] = 0;
	for (int i = 0; i < k; i++)//k개 명령을 받음
	{
		scanf("%d", &order);
		if (order == 1)//명령이 paint인 경우
		{
			scanf("%d %d %d", &a, &b, &color);
			paint(a, b, color);//a->b로가는 모든 경로를 color로 칠함
		}
		else
		{
			scanf("%d %d", &a, &b);
			if (order == 2)//명령이 move인 경우
			{
				move(a, b);
			}
			else//명령이 count 인경우
			{
				
				printf("%d\n", count(a, b));
			}
		}
	}
}
