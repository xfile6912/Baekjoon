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
	priority_queue<int> pq;
	int t;
	int i,j;
	int n, m;
	scanf("%d", &t);
	int priority[100];
	int print;
	int cnt = 0;
	for (i = 0; i < t; i++)
	{
		cnt = 0;
		scanf("%d %d", &n, &m);
		for (j = 0; j < n; j++)
		{
			q.push(j);//문서들을 큐에넣어줌;
			scanf("%d", &priority[j]);
			pq.push(priority[j]);//우선순위를 우선순위큐에 넣어줌.
		}
		while (1)
		{
			if (priority[q.front()] == pq.top())//만약에 우선순위큐의 탑에 있는 우선순위와 현재 큐의 맨 앞에 있는 문서의 우선순위가 같다면 출력 할 수 있다.
			{
				cnt++;
				print = q.front();//출력해주는 문서번호 저장
				q.pop();
				pq.pop();
				if (print == m)//출력하는 문서가 m이라면 while문 종료
					break;
			}
			else//다르면 큐의 맨앞에 있는 문서를 큐의 맨 뒤로 집어넣는다.
			{
				int temp = q.front();
				q.pop();
				q.push(temp);
			}
		}
		while (!q.empty())//다음 테스트케이스를 위해서 큐를 비워준다.
			q.pop();
		while (!pq.empty())//다음 테스트케이스를 위해서 우선순위큐를 비워준다.
			pq.pop();
		printf("%d\n", cnt);
	}

}
