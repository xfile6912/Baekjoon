#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	int i;
	int start, end, term;
	
	scanf("%d", &n);
	int cnt = 0;
	int laststart;
	vector<vector<int> > meetings(n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &start, &end);
		meetings[i].push_back(start);
		meetings[i].push_back(end);
	}
	sort(meetings.begin(), meetings.end());
	cnt++;//마지막 회의
	laststart = meetings[n - 1][0];//초기화
	for (i = n - 2; i >= 0; i--)
	{
		if (meetings[i][1] <= laststart)//해당 미팅이 끝나는 시점이 이미 정해둔 다음 미팅시작의 이전이거나 같다면 해당미팅을 추가해줌.
		{
			cnt++;
			laststart = meetings[i][0];
		}
	}
	printf("%d", cnt);
}
