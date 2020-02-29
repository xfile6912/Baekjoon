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
	deque<int> q;
	string order;
	int n;
	int num;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		cin >> order;
		if (order == "push_front")
		{
			cin >> num;
			q.push_front(num);
			continue;
		}
		if (order == "push_back")
		{
			cin >> num;
			q.push_back(num);
			continue;
		}
		if (order == "pop_front")
		{
			if (q.empty())
				printf("-1\n");
			else
			{
				printf("%d\n", q.front());
				q.pop_front();
			}
			continue;
		}
		if (order == "pop_back")
		{
			if (q.empty())
				printf("-1\n");
			else
			{
				printf("%d\n", q.back());
				q.pop_back();
			}
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
			{
				printf("0\n");
			}
			continue;
		}
		if (order == "front")
		{
			if (q.empty())
				printf("-1\n");
			else
			{
				printf("%d\n", q.front());
			}
			continue;
		}
		if (order == "back")
		{
			if (q.empty())
				printf("-1\n");
			else
			{
				printf("%d\n", q.back());
			}
			continue;
		}
	}
}
