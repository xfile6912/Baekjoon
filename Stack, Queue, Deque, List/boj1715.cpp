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
	priority_queue<int, vector<int>, greater<int> > q;
	int n;
	int i;
	int temp;
	int result = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		q.push(temp);
	}
	while (1)
	{
		if (q.size() == 1)
			break;
		int temp1 = q.top();
		q.pop();
		int temp2 = q.top();
		q.pop();
		result += temp1 + temp2;
		q.push(temp1 + temp2);
	}
	printf("%d", result);
}
