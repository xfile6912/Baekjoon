#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int dp[4001][4001];
string a;
string b;
void init()
{
	int i, j;
	for (i = 0; i < 4001; i++)
		for (j = 0; j < 4001; j++)
			dp[i][j] = 0;
}


int main(void)
{
	cin >> a >> b;
	int an = a.size();
	int bn = b.size();
	init();//dp배열 초기화
	int i, j;
	for (i = 0; i <= an; i++)
	{
		for (j = 0; j <= bn; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else
			{
				if (a[i-1] == b[j-1])//스트링 안에 있는 a의 i번째 문자와, b의 j번째 문자가 같을 때; 연속하게 찾아야 하므로 lcs와는 다름.
					dp[i][j] = dp[i - 1][j - 1] + 1;
			}
		}
	}
	int max = 0;
	for (i = 0; i <= an; i++)//전체  dp를 검색하면서 최댓값 찾음.
	{
		for (j = 0; j <= bn; j++)
		{
			if (max < dp[i][j])
				max = dp[i][j];
		}
	}
	printf("%d", max);
}
