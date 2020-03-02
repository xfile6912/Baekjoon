#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include <list>
using namespace std;


int main(void)
{
	string s;
	char space;//space받음
	char enter;//enter받음
	char temp;//명령어가 p일경우에 추가할 문자
	char order;//명령어
	int m;
	list<char>::iterator it;//커서
	cin >> s >> m;
	list<char> li;
	int i;
	for (i = 0; i < s.size(); i++)
	{
		li.push_back(s[i]);
	}
	it = li.end();
	for (i = 0; i < m; i++)
	{
		scanf("%c", &enter);//엔터 받아줌.
		scanf("%c", &order);
		if (order == 'P')
		{
			scanf("%c", &space);//order뒤에 스페이스가 있으므로 스페이스 받아줌
			scanf("%c", &temp);//명령어가 p일경우 추가할문자.
			if (it == li.end())
			{
				li.push_back(temp);
				it = li.end();
			}
			else
			{
				li.insert(it, temp);
			}
			continue;
		}
		if (order == 'L')
		{
			if (it == li.begin())
			{

			}
			else
				it--;
			continue;
		}
		if (order == 'D')
		{
			if (it == li.end())
			{

			}
			else
				it++;
			continue;
		}
		if (order == 'B')
		{
			if (it == li.begin())
			{

			}
			else
			{
				if (it == li.end())
				{
					it--;
					li.erase(it);
					it = li.end();
				}
				else
				{
					it--;
					it=li.erase(it);
				}
				
			}
			continue;
		}
	}
	for (it = li.begin(); it != li.end(); it++)
	{
		printf("%c", *it);
	}
}
