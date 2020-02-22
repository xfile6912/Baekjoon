#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
using namespace std;

bool compare(vector<int> x, vector<int> y)
{
	return x[1] < y[1];
}

int main(void)
{
	int n;
	int i;
	int maxvalue;
	scanf("%d", &n);
	priority_queue<vector<int>> q;
	int cnt;
	vector<vector<int> > info(n, vector<int>( 3,0));//[1]arrive time//[2] needed time//[0]priority;
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &info[i][1], &info[i][2]);
		info[i][0] = n-i;
	}
	sort(info.begin(), info.end(), compare);//목장 도착시간 순으로 정렬
	int flag;
	vector<int> cow;
	q.push(info[0]);//최초로 도착한 소를 프라이어리티큐에 넣어줌.
	for (i = 1; i < n; i++)//최초 도착한 소들을 프라이어리티 큐에 넣어줌.
	{
		if (info[0][1] == info[i][1])
			q.push(info[i]);
		else
		{
			flag = i;
			break;
		}
	}
	cow = q.top();//목장에 입장하는 소
	q.pop();
	cnt = cow[1];//현재 소가 목장에 입장한 시간
	maxvalue = 0;//첫 소가 기다린 시간은 0이다.

	while (1)
	{
		cnt += cow[2];//현재 소가 식사를 마친 시간;
		for (i = flag; i < n; i++)
		{
			if (info[i][1] <= cnt)//소가 식사를 마칠 때까지 기다리는 소들을 다 큐에 넣어준다.
				q.push(info[i]);
			else
			{
				break;
			}
		}
		flag = i;
		if (flag == n && q.empty())//모든 소가 끝났을 때//종료 조건
			break;
		if (q.empty())//현재 소는 식사가 끝났는데 기다리는 소가 없고 다음 목장에 입장할 소는 현재시간 다음에 들어올 때
		{
			q.push(info[flag]);//프라이어리티 큐에 넣어줌.
			cnt = info[flag][1];
			for (i = flag+1; i < n; i++)//소들을 프라이어리티 큐에 넣어줌.
			{
				if (info[flag][1] == info[i][1])
					q.push(info[i]);
				else
				{
					break;
				}
			}
			flag = i;
		}
		cow = q.top();//새로 목장에 식사를 하러 입장하는 소(새로운 소, 현재 소라고 지칭)
		q.pop();
		maxvalue = max(maxvalue,cnt - cow[1]);//현재 소가 기다린 시간.
	}

	printf("%d", maxvalue);
}
