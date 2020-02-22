#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool compare(vector<int> x, vector<int> y)
{
	if (x[0] == y[0])
		return x[1] > y[1];
	return x[0] < y[0];
}


int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int> > info(n, vector<int>(2, 0));//[0]=가격, [1]=무게;
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &info[i][1], &info[i][0]);
	}
	sort(info.begin(), info.end(),compare);//가격이 다를 경우엔 가격이 낮은 순으로 정렬//가격이 같은경우에는 무게가 큰순으로
	int result= 2147483647;
	int sum=0;
	
	sum += info[0][1];
	int flag=0;
	if (sum >= m)
	{
		result = info[0][0];
		flag = 1;
	}
	int cnt=1;

	for (i = 1; i < n; i++)
	{
		sum += info[i][1];
		if (info[i][0] == info[i - 1][0])
			cnt++;
		else
			cnt = 1;

		if (sum >= m)
		{
			result=min(result, info[i][0]*cnt);
			flag = 1;
		}
	}
	if (flag == 1)
		printf("%d", result);
	else
		printf("-1");
}
