#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
int cnt = 0;
int n;
vector<vector<int> > house(16, vector<int>(16, 0));
void dfs(int flag, int starti, int startj)//flag가 0이면 가로, 1이면 세로, 2= 대각선
{
	if (flag == 0)//가로
	{
		if (starti == n - 1 && startj + 1 == n - 1)
		{
			cnt++;
			return;
		}
		if(startj+2<n&& house[starti][startj + 2] != 1)
			dfs(0, starti, startj + 1);
		if(starti + 1 < n && startj + 2 < n&&house[starti+1][startj+1] !=1 && house[starti][startj + 2] != 1 && house[starti+1][startj+2]!=1 )
			dfs(2, starti, startj + 1);
	}
	else if (flag == 1)//세로
	{
		if (starti+1 == n - 1 && startj == n - 1)
		{
			cnt++;
			return;
		}
		if(starti + 2 < n &&house[starti+2][startj]!=1 )
			dfs(1, starti + 1, startj);
		if(starti + 2 < n && startj + 1 < n &&house[starti + 1][startj+1] != 1 && house[starti + 2][startj] != 1 && house[starti+2][startj+1]!=1 )
			dfs(2, starti + 1, startj);
	}
	else//대각선
	{
		if (starti+1 == n - 1 && startj + 1 == n - 1)
		{
			cnt++;
			return;
		}
		if (startj + 2 < n &&house[starti+1][startj + 2] != 1 )
			dfs(0, starti + 1, startj + 1);
		if (starti + 2 < n &&house[starti + 2][startj+1] != 1 )
			dfs(1, starti + 1, startj + 1);
		if(starti + 2 < n && startj + 2 < n&&house[starti + 1][startj + 2] != 1 && house[starti + 2][startj+1] != 1 && house[starti+2][startj+2]!=1 )
			dfs(2, starti + 1, startj + 1);
	}
}
int main(void)
{

	scanf("%d", &n);
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &house[i][j]);
		}
	}
	dfs(0, 0, 0);
	printf("%d", cnt);
}
