#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(void)
{
	int t;
	int n;
	int i, j, k;
	int cnt = 0;
	scanf("%d", &t);
	for (k = 0; k < t; k++)
	{
		scanf("%d", &n);
		cnt = 0;
		vector<vector<int> > info(n, vector<int>(2, 0));
		vector<int> flag(n, 0);//만약에 flag가 1이면 회사에 입사할 수 있음.
		for (i = 0; i < n; i++)
		{
			scanf("%d %d", &info[i][0], &info[i][1]);
		}
		sort(info.begin(), info.end());//서류 순위 순으로 정렬
		int last = 0;
		flag[0] = 1;
		for (i = 1; i < n; i++)
		{
			if (info[i][1] < info[last][1])//서류상으로 정렬 되어 있기 때문에 면접순위가 위의사람보다 높으면 붙음.
			{
				flag[i] = 1;
				last = i;
			}//또한 서류상으로 정렬되어 있기때문에 합격이 확정된 사람 중들에 서류 점수상으로 
			//바로 위에 있는 사람의 면접 점수보다 면접 점수가 높으면 됨.
		}
		for (i = 0; i < n; i++)
		{
			if (flag[i] == 1)
				cnt++;
		}
		printf("%d\n", cnt);
	}
}
