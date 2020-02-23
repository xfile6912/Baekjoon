#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
using namespace std;
vector<vector<int> > a(50,vector<int>(50, 0));
vector<vector<int> > b(50, vector<int>(50, 0));


void change(int y, int x)
{
	int i, j;
	for (i = y; i < y+3; i++)
	{
		for (j = x; j < x + 3; j++)
		{
			if (a[i][j] == 0)
				a[i][j] = 1;
			else
				a[i][j] = 0;
		}
	}
}


int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);


	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			scanf("%1d", &a[i][j]);
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			scanf("%1d", &b[i][j]);
	}
	int cnt = 0;
	for (i = 0; i <= n-3; i++)//왼쪽위부터 시작해서 a[i][j]랑 b[i][j]가 다르면 3*3 부분행렬을 바꾸어줌.
	{
		for (j = 0; j <= m-3; j++)
		{
			if (a[i][j] != b[i][j])
			{
				change(i, j);
				cnt++;
			}
		}
	}
	int flag = 1;
	for (i = 0; i < n ; i++)
	{
		for (j = 0; j < m; j++)
			if (a[i][j] != b[i][j])
				flag = 0;
	}
	if (flag == 0)
		printf("-1");
	else
		printf("%d", cnt);
}
