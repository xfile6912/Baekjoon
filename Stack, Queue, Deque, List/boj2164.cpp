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
	int n;
	int i;
	scanf("%d", &n);
	int temp;
	for (i = 1; i <= n; i++)//1부터 n까지의 카드를 덱에 넣어줌
	{
		q.push_back(i);
	}
	while (1)
	{
		if (q.size() == 1)//덱에 한장의 카드가 남게되면 끝낸다.
			break;
		q.pop_front();//가장 위에 있는 카드를 한장 버림;
		temp=q.front();//가장 위에 있는 카드를 밑으로 옮김
		q.pop_front();
		q.push_back(temp);
	}
	printf("%d", q.front());
}
