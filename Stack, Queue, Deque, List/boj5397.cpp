#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include <list>
using namespace std;


int main(void)
{
	int t;
	string s;
	list<char> li;
	list<char>::iterator it;
	int i,j;
	it = li.end();
	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		cin >> s;
		for (j = 0; j < s.size(); j++)
		{
			if (s[j] == '<')
			{
				if(it != li.begin())
				it--;
				continue;
			}
			if (s[j] == '>')
			{
				if (it != li.end())
					it++;
					continue;
			}
			if (s[j] == '-')
			{
				if(it != li.begin())
					it=li.erase(--it);
				continue;
			}
			li.insert(it, s[j]);
		}
		for (it = li.begin(); it != li.end(); it++)
			printf("%c", *it);
		printf("\n");
		li.clear();
	}
}
