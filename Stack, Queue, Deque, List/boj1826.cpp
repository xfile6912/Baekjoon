#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;



int main(void)
{	
	int n;

	priority_queue<int> q;
	int distance, fuel;
	int cnt = 0;
	int i;
	scanf("%d", &n);
	vector<vector<int> > info(n, vector<int>(2, 0));
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &info[i][0], &info[i][1]);
	}
	scanf("%d %d", &distance, &fuel);

	sort(info.begin(), info.end());//거리순으로 정렬;
	distance = distance - info[n - 1][0];
	for (i = n-1; i > 0; i--)
	{
		info[i][0] = info[i][0] - info[i - 1][0];//info[i][0]에는 이전 주유소와의 거리가 저장되있음
	}
	int flag;
	flag = 1;
	for (i = 0; i < n; i++)
	{
		fuel = fuel - info[i][0];
		if (fuel < 0)
		{
			while (fuel<0)
			{
				if (q.empty())//기름이 없어 다음 주유소로 못가는경우
				{
					flag = 0;
					break;
				}
				fuel += q.top();//기름을 넣어줌
				q.pop();
				cnt++;
			}
		}
		if (flag == 0)
		{
			break;
		}
		q.push(info[i][1]);
	}
	if (flag == 0)
		printf("-1");
	else
	{
		fuel = fuel - distance;
		if (fuel >= 0)
			printf("%d", cnt);
		else
		{
			while (fuel < 0)
			{
				if (q.empty())//마을까지 못가는경우
				{
					flag = 0;
					break;
				}
				fuel += q.top();//기름을 넣어줌
				q.pop();
				cnt++;
			}
			if (flag == 0)
				printf("-1");
			else
				printf("%d", cnt);
		}
	}
}
