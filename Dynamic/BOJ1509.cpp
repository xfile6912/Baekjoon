#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

string pal;
int dp[2500][2500];
int n;
int dp1[2500];
int solve(int start)//
{
	int &ret = dp1[start];
	if (start == n)
		return 0;
	if (ret != 987654321)
		return ret;
	ret = 987654321;
	int i;
	for (i = start; i < n; i++)
	{
		if(dp[start][i]==1)
			ret = min(ret, solve(i + 1));
	}
	if (ret != 987654321)
		ret = ret + 1;
	return ret;
}


int main()
{
	cin >> pal;
	int i, j;
	n = pal.size();
	for (i = 0; i < 2500; i++)
    {
		dp1[i] = 987654321;
        for(j=0; j<2500; j++)
            dp[i][j]=0;
    }
	i = 0; j = 0;
	int lastj = j;
	while (1)//i~j까지가 팰린드롬인지 확인해서 dp[i][j]에 저장
	{
		if (j == n)
		{
			i = 0;
			j = lastj + 1;
			lastj = j;

		}
		if (i == 0 && j == n)
			break;
		if (i == j)
			dp[i][j] = 1;
		if (j == i + 1)
		{
			if (pal[i] == pal[j])
				dp[i][j] = 1;
		}
		else
		{
			if (dp[i + 1][j - 1] == 1 && pal[i] == pal[j])
				dp[i][j] = 1;
		}
		i++;
		j++;
	}
	int result = 987654321;
	for (i = 0; i < n; i++)
	{
		if(dp[0][i]==1)
			result = min(result, solve(i+1)+1);
	}
	printf("%d", result);
}
