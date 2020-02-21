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
	string b;
	int i,j;
	int cnt = 0;
	cin >> a >> b;

	if (a.size() == b.size())
	{
		for (i = 0; i < a.size(); i++)
		{
			if (a[i] != b[i])
				cnt++;
		}
		printf("%d", cnt);
		return 0;
	}
	else
	{
		int minvalue=987654321;
		for (j = 0; j <= b.size() - a.size(); j++)//b문자열의 인덱스 시작지점을 계속 바꿔주면서 대조해서 가장 작은값 찾으면 됨
		{//가장 작은 값을 가지는 b문자열의 인덱스 시작지점에 a문자열을 놓고 나머지는 b랑 똑같이 맞춰주면 되기 때문.
			cnt = 0;
			for (i = 0; i < a.size(); i++)
			{
				if (b[j + i] != a[i])
					cnt++;
			}
			minvalue = min(minvalue, cnt);
		}
		printf("%d", minvalue);
	}
}
