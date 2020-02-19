#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int info[1001];

int increase[1001];//증가부분순열
int decrease[1001];//감소부분순열이지만, 뒤에서부터 인덱스 0까지 증가하는 부분순열 형태로 저장

int main(void)
{
	int n;
	scanf("%d", &n);
	int i, j;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &info[i]);
	}
	increase[0] = 1;
	for (i = 0; i < n; i++)
	{
		increase[i] = 1;
		decrease[i] = 1;
	}
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (info[i] < info[j] && increase[j]<increase[i]+1)
				increase[j] = increase[i] + 1;
		}
	}
	for (i = n-1; i >= 0; i--)
	{
		for (j = i - 1; j >= 0; j--)
		{
			if (info[i] < info[j] && decrease[j] < decrease[i] + 1)
				decrease[j] = decrease[i] + 1;
		}
	}
	int max=increase[0]+decrease[0];
	for (i = 1; i < n; i++)
		if (max < increase[i] + decrease[i])
			max = increase[i] + decrease[i];
	printf("%d", max - 1);
}
