#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;


//가장 긴 부분 증가 순열을 찾으면 된다.
int main()
{
	int n;
	int info[200];
	int dp[200];
	scanf("%d", &n);
	int i,j;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &info[i]);
		dp[i] = 1;
	}
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (info[j] > info[i] && dp[j] < dp[i] + 1)
				dp[j] = dp[i] + 1;
		}
	}
	int maxvalue = 0;
	for (i = 0; i < n; i++)
	{
		if (maxvalue < dp[i])
			maxvalue = dp[i];
	}
	printf("%d", n - maxvalue);
}
