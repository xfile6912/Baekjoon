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
	int n, k;
	scanf("%d %d", &n, &k);
	int i;
	for (i = 1; i <= n; i++)
	{
		q.push(i);
	}
	int cnt = 1;
	printf("<");
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		if (cnt != k)//만약에 k번째가 아니라면 다시 q에 넣어준다.
		{
			q.push(temp);
			cnt++;
		}
		else
		{
			if (q.empty())//마지막 숫자를 뺄 때는 ,를 출력하면 안되므로
				printf("%d", temp);
			else
				printf("%d, ",temp);
			cnt = 1;
		}
	}
	printf(">");
}
