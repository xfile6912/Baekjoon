#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
using namespace std;


int main(void)
{
	queue<int> q;
	string order;
	int num;//push일 경우에 큐에 숫자 넣어줌.
	int n;
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
	{
		cin >> order;
		if (order == "push")
		{
			cin >> num;
			q.push(num);
			continue;
		}
		if (order == "pop")
		{
			if (!q.empty())
			{
				printf("%d\n", q.front());
				q.pop();
			}
			else
				printf("-1\n");
			continue;
		}
		if (order == "size")
		{
			printf("%d\n", q.size());
			continue;
		}
		if (order == "empty")
		{
			if (q.empty())
				printf("1\n");
			else
				printf("0\n");
			continue;
		}
		if (order == "front")
		{
			if (!q.empty())
				printf("%d\n", q.front());
			else
				printf("-1\n");
			continue;
		}
		if (order == "back")
		{
			if (!q.empty())
				printf("%d\n", q.back());
			else
				printf("-1\n");
			continue;
		}
		
	}
}
