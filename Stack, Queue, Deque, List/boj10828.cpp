#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <stack>
using namespace std;

int main(void)
{
	stack<int> s;
	int n;//명령의 수;
	scanf("%d", &n);
	int i;
	string order;//명령
	int num;//push할 숫자 저장
	for (i = 0; i < n; i++)
	{
		cin >> order;
		if (order == "push")
		{
			cin >> num;
			s.push(num);
			continue;
		}
		if (order == "pop")
		{
			if (s.empty())
				printf("-1\n");
			else
			{
				printf("%d\n", s.top());
				s.pop();
			}
			continue;
		}
		if (order == "size")
		{
			printf("%d\n", s.size());
			continue;
		}
		if (order == "empty")
		{
			if (s.empty())
				printf("1\n");
			else
				printf("0\n");
			continue;
		}
		if (order == "top")
		{
			if (s.empty())
				printf("-1\n");
			else
				printf("%d\n",s.top());
			continue;
		}
	}
}
