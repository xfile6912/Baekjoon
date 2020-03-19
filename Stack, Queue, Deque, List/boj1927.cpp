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
	priority_queue<int, vector<int>, greater<int>> q;
	scanf("%d", &n);
	int i, order;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &order);
		if (order == 0)
		{
			if (q.empty())
				printf("0\n");
			else
			{
				printf("%d\n", q.top());
				q.pop();
			}
		}
		else
			q.push(order);
	}
}
