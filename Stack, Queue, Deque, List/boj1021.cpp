#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include <queue>
using namespace std;


int main(void)
{
	deque<int> q;
	int n, m;
	int flag = 1;//flag가 0이면 왼쪽으로 이동시켜 뽑고, 1이면 오른쪽으로 이동시켜 뽑는다.
	int i,j;
	int result = 0;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		q.push_back(i);//덱에 1부터 n까지 집어넣음.
	}

	vector<int> v(m, 0);//뽑으려고 하는 수의 배열
	for (i = 0; i < m; i++)
	{
		scanf("%d", &v[i]);
	}

	for (i = 0; i < m; i++)
	{
		flag = 1;
		for (j = 0; j < (q.size()+1)/2; j++)//절반까지 찾아보고 만약에 절반내에 있으면 왼쪽으로 이동시키면 된다.//없으면 오른쪽으로 이동시킴
		{
			if (q[j] == v[i])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 0)
		{
			while (q.front() != v[i])//해당 원소가 나올때까지 왼쪽으로 이동시켜줌
			{
				int temp=q.front();
				q.pop_front();
				q.push_back(temp);
				result++;
			}
			q.pop_front();//해당원소 팝해줌;
		}
		else
		{
			while (q.front() != v[i])//해당 원소가 나올때까지 오른쪽으로 이동시켜줌
			{
				int temp = q.back();
				q.pop_back();
				q.push_front(temp);
				result++;
			}
			q.pop_front();//해당원소 팝해줌;
		}
	}
	printf("%d", result);
}
