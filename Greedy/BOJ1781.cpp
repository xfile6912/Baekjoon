#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
using namespace std;

bool compare(vector<int> a, vector<int> b)
{
	if (a[1] == b[1])
		return a[0] < b[0];
	return a[1] < b[1];
}

int main(void)
{
	int n;
	int i;
	scanf("%d", &n);
	vector<vector<int> > info(n, vector<int>(2, 0));//[1]은 데드라인, [0]은 컵라면 수
	priority_queue<vector<int> > q;
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &info[i][1], &info[i][0]);
	}
	sort(info.begin(), info.end(), compare);//데드라인으로 정렬; 데드라인이 같으면 컵라면수로 정렬
	int deadline=info[n-1][1];//뒤에서부터 확인
	int result = 0;
	for (i = n - 1; i > 0; i--)
	{
		if (deadline == info[i][1])//데드라인과 문제의 데드라인이 같으면 큐에 집어 넣어줌
		{
			q.push(info[i]);
		}
		else//문제의 데드라인이 데드라인보다 작으면 데드라인에 해결할 문제를 큐에서 꺼내 풀어서 컵라면을 얻는다.
		{//프라이어티큐안에는 문제의 데드라인이 데드라인과 같거나 데드라인보다 늦는 문제들이 컵라면 수가 많은 순서대로 정렬되어있음
			if (!q.empty())
			{
				result += q.top()[0];
				q.pop();
			}
			deadline--;
			i++;
		}
	}
	while (deadline >= 1 && !q.empty())
	{
		result += q.top()[0];
		q.pop();
		deadline--;
	}
	printf("%d", result);
}
