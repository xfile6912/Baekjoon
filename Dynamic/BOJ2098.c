#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int info[16][16];
int dp[16][1 << 16];//비트마스킹 이용
int n;
int dfs(int start, int visit)
{
	int i;
	if (visit == (1 << n) - 1)//모든 곳을 다 방문하고 처음 출발점으로 돌아가는 경우;
	{
		if (info[start][0] != 0)//돌아가는 길이 있다면 돌아가는 길의 거리 리턴
			return info[start][0];
		return 1000000000;//없다면 최대값 넣어줌.
	}
	int &ret=dp[start][visit];

	if (ret != -1)
		return ret;
	ret = 1000000000;





	for (i = 0; i < n; i++)
	{
		if (info[start][i] != 0 && ((visit>>i)&1)==0)//현재지점으로부터 i점 까지의 길이 있고, i를 방문하지 않았을 때 방문해줌.
		{
			ret=min(ret,dfs(i,visit|(1<<i))+info[start][i]);
		}
	}
	return ret;
}
int main(void)
{
	scanf("%d", &n);
	int i, j;

	for (i = 0; i < 16; i++)//dp배열 초기화
	{
		for (j = 0; j <(1 << 16); j++)
			dp[i][j] = -1;
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &info[i][j]);
		}
	}
	printf("%d\n",dfs(0,1));//결국에는 사이클이 생기므로 최소경우는 어디서 출발하든 다 같으므로 한 가지만 계산해주면 됨.
}
