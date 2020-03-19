#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct node {
	int absvalue;
	int value;
};

bool operator<(node a, node b)
{
	if (a.absvalue == b.absvalue)
		return a.value > b.value;
	return a.absvalue > b.absvalue;
}

int main(void)
{
	int n;
	priority_queue<node> q;
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
				printf("%d\n", q.top().value);
				q.pop();
			}
		}
		else
		{
			node temp;
			temp.absvalue = abs(order);
			temp.value = order;
			q.push(temp);
		}
	}
}
