#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<vector<int> > arr(1000001);
int visited[1000001];

int maxvalue = 1000001;

int dp[1000001][2];

int solve(int point, int flag)//point=현재지점, flag=얼리어댑터인지 아닌지 1일경우에 얼리어댑터
{
	int i;
	int &ret = dp[point][flag];
	if (ret != -1)
		return ret;
	ret = 0;
	for (i = 0; i < arr[point].size(); i++)
	{
		if (visited[arr[point][i]] == 0)
		{
			visited[arr[point][i]] = 1;
			if (flag == 0)//현재 얼리어댑터가 아니라면 자식들은 무조건 얼리어댑터여야 함.
			{
				ret += solve(arr[point][i], 1)+1;
			}
			else//현재 얼리어댑터라면 자식들은 얼리어댑터일수도있고 아닐수도 있음.
			{
				ret	+= min(solve(arr[point][i], 1) + 1, solve(arr[point][i], 0));
			}
			visited[arr[point][i]] = 0;
		}
	}
	return ret;
}

int main()
{
	int n;
	int v1, v2;//vertex;
	scanf("%d", &n);
	int i;
	for (i = 0; i < 1000001; i++)
	{
		dp[i][0] = -1;
		dp[i][1] = -1;
		visited[i] = 0;
	}
	for (i = 0; i < n-1; i++)
	{
		scanf("%d %d", &v1, &v2);
		arr[v1].push_back(v2);
		arr[v2].push_back(v1);
	}
	visited[1] = 1;
	printf("%d", min(solve(1, 1)+1, solve(1, 0)));//시작점은 얼리어댑터일수도있고 아닐수도 있음
}
