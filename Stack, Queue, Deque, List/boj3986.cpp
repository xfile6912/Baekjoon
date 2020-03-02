#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include <stack>
using namespace std;


int main(void)
{
	int n;
	int result = 0;
	stack<char> st;
	string s;
	scanf("%d", &n);
	int i, j;
	for (i = 0; i < n; i++)
	{
		cin >> s;
		for (j = 0; j < s.size(); j++)
		{
			if (st.empty())
			{
				st.push(s[j]);
			}
			else if (st.top() != s[j])
				st.push(s[j]);
			else
				st.pop();
		}
		if (st.empty())
			result++;
		else
		{
			while (!st.empty())
				st.pop();
		}
	}
	printf("%d", result);
}
