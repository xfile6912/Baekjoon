#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	int i,j;
	vector<vector<int> > info(m, vector<int>(2, 0));//[0]은 패키지 , [1]은 낱 개
	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &info[i][0], &info[i][1]);
	}
	sort(info.begin(), info.end());
	int minvalue = 987654321;
	for (i = 0; i < m; i++)
	{
		minvalue = min(minvalue, info[i][1] * n);
		minvalue = min(minvalue, info[i][0] * ((n - 1) / 6 + 1));
		for (j = 0; j < m; j++)
		{
			minvalue = min(minvalue, info[i][0] * (n / 6) + info[j][1] * (n % 6));
		}
	}
	printf("%d", minvalue);
}
