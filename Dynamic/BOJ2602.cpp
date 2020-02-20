#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

string pat;
string a;//악마다리
string b;//천사다리

int dp[2][20][100];//순서대로 다리 종류, 패턴인덱스, 인덱스 순서.

int solve(int flag,int patindex,int index)//flag=0일경우에 악마의 다리, flag=1일 경우에 천사의 다리,패턴인덱스와, 다리 인덱스.
{
	if (patindex == pat.size())
		return 1;
	if (index == a.size())
		return 0;
	int &ret = dp[flag][patindex][index];
	if (ret != -1)
		return ret;
	ret = 0;
	int i;
	if (flag == 0)
	{
		for (i = index; i < a.size(); i++)
		{
			if (a[i] == pat[patindex])
				ret += solve(1, patindex + 1, i + 1);
		}
	}
	if (flag == 1)
	{
		for (i = index; i < a.size(); i++)
		{
			if (b[i] == pat[patindex])
				ret += solve(0, patindex + 1, i + 1);
		}
	}
	return ret;
}

int main()
{

	cin >> pat >> a >> b;
	int i,j;
	int cnt=0;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 100; j++)
		{
			dp[0][i][j] = -1;
			dp[1][i][j] = -1;
		}
	}
	for (i = 0; i < a.size(); i++)
	{
		if (a[i] == pat[0])//악마다리에서 시작하는경우;
			cnt+= solve(1, 1, i+1);//천사다리의 i+1부터 다음 패턴을 찾음.
		if (b[i] == pat[0])//천사다리에서 시작하는경우
			cnt += solve(0, 1, i + 1);//악마다리의 i+1부터 다음 패턴을 찾음.
	}
	printf("%d", cnt);
}
