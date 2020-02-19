#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int info[40001];
vector<int> dp;

//부분 증가 순열
int main(void)
{
	int n;
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &info[i]);
	}
	int j;
	dp.push_back(info[0]);
	for (i = 1; i < n; i++)
	{
		if (info[i] > dp.back())
			dp.push_back(info[i]);
		else
		{
			dp[lower_bound(dp.begin(), dp.end(), info[i])-dp.begin()]=info[i];
		}
	}
	printf("%d", dp.size());
}
