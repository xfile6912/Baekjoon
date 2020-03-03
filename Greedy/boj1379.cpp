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
	return a[2] < b[2];
}

bool compare1(vector<int> a, vector<int> b)
{
	return a[1] < b[1];
}


int main(void)
{
	int n;//강의 개수
	scanf("%d", &n);
	vector<vector<int> > lecture(n + 1, vector<int>(4, 0));//[2]=강의번호,[0]=강의시작시간,[1]=강의 종료시간,[3] 배정강의실
	int i;
	int classroom = 1;
	priority_queue<vector<int> > q;
	for (i = 1; i <= n; i++)
	{
		scanf("%d %d %d", &lecture[i][2], &lecture[i][0], &lecture[i][1]);
	}
	sort(lecture.begin(), lecture.end(), compare1);//강의 종료순서대로 정렬해줌.
	lecture[n][3] = classroom++;
	q.push(lecture[n]);
	for (i = n - 1; i >= 1; i--)
	{
		vector<int> temp = q.top();
		if (lecture[i][1] <= temp[0])//여러 강의실 중에서 다음 강의의 시작시간이 가장 나중인 곳에 강의를 집어넣음.
		{//전제 조건은 현재 강의가 끝나는 시간이 다음 강의의 시작시간 전이어야함.
			lecture[i][3] = temp[3];
			q.pop();
			q.push(lecture[i]);
		}
		else//현재 강의가 끝나는시간이 다음 강의의 시작시간 이후라면 새로 강의실을 만들어줘야함.
		{//다음 강의의 시작 시간이 가장 나중인 곳을 이미 골라 주었으므로 그 외 강의실에는 당연히 못 배정 받음.
			lecture[i][3] = classroom++;
			q.push(lecture[i]);
		}
	}
	printf("%d\n", q.size());
	sort(lecture.begin(), lecture.end(), compare);//강의 번호순으로 정렬
	for (i = 1; i <= n; i++)
	{
		printf("%d\n", lecture[i][3]);
	}


}
