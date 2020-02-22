#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(void)
{
	string a;
	vector<char> result;
	int k;
	int n;
	scanf("%d %d", &n, &k);
	cin >> a;
	int i, j;
	int temp = k;
	result.push_back(a[0]);
	for (i = 1; i < n; i++)//전체 순회
	{
		if (a[i] <= result[result.size() - 1] || temp==0)//이전것보다 작으면 집어넣음.
		{
			result.push_back(a[i]);
		}
		else
		{
			while (result.size() != 0 && result[result.size() - 1] < a[i] && temp!=0)//이전거보다 크다면 앞쪽에서 현재숫자보다 작은 것들을 지울수 있는 만큼 다 없애줌
			{
				result.pop_back();
				temp--;
			}
			result.push_back(a[i]);
		}

	}
	for (i = 0; i < n - k; i++)
	{
		printf("%c", result[i]);
	}
}
