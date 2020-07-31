#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

long long getcount(long long number)
{
	long long count=0;
	queue<long long> q;
	if (number >= 4 && number<7)
	{
		q.push(4);
	}
	if (number >= 7)
	{
		q.push(4);
		q.push(7);
	}
	while (!q.empty())
	{
		if (q.front() * 10 + 4 > number)
		{
			break;
		}
		if (q.front() * 10 + 4)
		{
			q.push(q.front() * 10 + 4);
		}
		if (q.front() * 10 + 7 > number)
			break;
		if (q.front() * 10 + 7)
		{
			q.push(q.front() * 10 + 7);
			q.pop();
			count++;
		}
	}
	count += q.size();
	return count;
}

int main(void)
{
	long long start, end;
	cin >> start >> end;
	long long counts = getcount(start);
	long long counte = getcount(end);
	int flag = 1;//start수가 금민수인지를 체크
	while (start != 0)
	{
		if (start % 10 != 4 && start % 10 != 7)
		{
			flag = 0;//금민수가 아님
			break;
		}
		start = start / 10;
	}
	if (flag == 1)//금민수임
		counts = counts - 1;
	cout<<counte- counts;
}
