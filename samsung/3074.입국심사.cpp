#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void)
{
	int testCase;
	int n, m;//입국심사대 수, 사람 수
	scanf("%d", &testCase);
	int i, j, k, l;
	for (k = 1; k <= testCase; k++)
	{
		scanf("%d %d", &n, &m);
		vector<int> time(n, 0);
		int maxTime=0;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &time[i]);
			maxTime = max(time[i], maxTime);
		}
		long long startTime=0;//시작 시간
		long long endTime=((long long)m)*maxTime;//최대로 걸리는시간
		//최소시간은 시작시간과 최대로 걸리는 시간 사이에 있음.
		long long mid;
		long long answer=endTime;
		while (startTime <= endTime)
		{
			mid = (startTime + endTime) / 2;
			long long peopleNum=0;//mid시간에 처리한 사람 수.
			for (i = 0; i < n; i++)
			{
				peopleNum += mid / time[i];
			}
			if (peopleNum < m)//mid시간에 처리한 사람 수가 m보다 작다면 mid시간보다는 오래걸림.
			{
				startTime = mid + 1;
			}
			else
			{
				answer = min(answer, mid);
				endTime = mid - 1;
			}
		}
		printf("#%d %lld\n", k, answer);
	}
}

