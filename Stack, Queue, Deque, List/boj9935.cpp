#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<string>
#include <vector>
#include<algorithm>
using namespace std;


int main(void)
{
	string s;
	string bomb;

	cin >> s;
	cin >> bomb;
	vector <char> st;
	int size=s.size();
	int patsize=bomb.size();
	int i, j,k;
	for (i = 0; i < size; i++)
	{
		st.push_back(s[i]);
		k = patsize - 1;
		int flag = 0;//flag가 1이면 폭탄문자열 찾음;
		for (j = st.size()-1; j >= 0; j--)
		{
			if (st[j] != bomb[k])
				break;
			if (k == 0)
			{
				flag = 1;
				break;
			}
			k--;
		}
		if (flag == 1)//폭탄문자열 찾은경우 스택에서 팝해줌
		{
			for (k = patsize - 1; k >= 0; k--)
				st.pop_back();
		}
	}
	if (st.size() == 0)
	{
		printf("FRULA");
		return 0;
	}
	for (i = 0; i < st.size(); i++)
		printf("%c", st[i]);
}
