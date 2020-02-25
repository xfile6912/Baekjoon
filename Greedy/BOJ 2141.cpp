#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
using namespace std;


//마을을 정렬하고 왼쪽 구역과 오른쪽 구역으로 나누어 왼쪽구역과, 오른쪽 구역의 사람수가 최대한 같아져야 한다.

int main(void)
{
	int n;
	scanf("%d", &n);
	vector<vector<int> >x(n, vector<int>(2, 0));//[0]은 마을의 위치 [1]은 사람의 수
	vector<long long> peoplenum(n, 0);//가장 왼쪽 마을부터 인덱스까지 사람수의 합
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &x[i][0], &x[i][1]);
	}
	sort(x.begin(), x.end());
	peoplenum[0] = x[0][1];
	for (i = 1; i < n; i++)//가장 왼쪽마을부터 인덱스 i까지의 사람수의 합을 저장해줌.
	{
		peoplenum[i] = peoplenum[i - 1] + x[i][1];
	}
	int flag = 0;
	for (i = 0; i < n; i++)
	{
		if (peoplenum[i] == peoplenum[n - 1] - peoplenum[i])//0부터 i까지의 사람의 수와, i+1~n-1까지 사람의 수가 같다면 i번째 마을에 우체국을 세우면 됨.
		{
			flag = 1;
			break;
		}
		if (i>0 &&peoplenum[i - 1] == peoplenum[n - 1] - peoplenum[i])//0~i-1까지의 사람의 수와, i+1~n-1까지 사람의 수가 같다면 i번째 마을에 세우면 됨.
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
	{
		printf("%d", x[i][0]);
	}
	else//만약에 왼쪽과 오른쪽 경우로 나누었을 때 사람수가 같게 쪼갤 수 없다면 
	{//처음으로 왼쪽의 사람수가 오른쪽의 사람수보다 많은 경우가 답.
		for (i = 0; i < n; i++)
		{
			if (peoplenum[i] > peoplenum[n - 1] - peoplenum[i])
				break;
		}
		printf("%d", x[i][0]);
	}
}
