#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <stack>
using namespace std;

int main(void)
{
	stack<int> st;
	string s;//괄호문자열
	int result=0;
	cin >> s;
	int flag = 1;//0이면 잘못된 문자열
	int i=0;//문자열 인덱스
	for (i = 0; i < s.size(); i++)
	{
		if (s[i] == '(' || s[i] == '[')
			st.push(s[i]);
		else
		{
			if (st.empty())//닫는괄호가 들어왔는데 스택이 비어있으면 잘못된 괄호열
			{
				flag = 0;
				break;
			}
			if (s[i] == ')' && st.top() == '(')
				st.pop();
			else if (s[i] == ']' && st.top() == '[')
				st.pop();
			else//닫는 괄호가 여는 괄호랑 매칭되지 않으면 잘못된 괄호열
			{
				flag = 0;
				break;
			}
		}
	}
	if (flag == 0 || !st.empty())//flag가 0이가나 다 순회했을때 스택이 비어있지 않다면 잘못된 문자열
	{
		flag = 0;
	}
	if (flag == 1)//올바른 문자열일 경우
	{
		i = 0;
		while (i < s.size())
		{
			if (s[i] == '(')
			{
				st.push(-1);
				i++;
				continue;
			}
			if (s[i] == '[')
			{
				st.push(-2);
				i++;
				continue;
			}
			if (s[i] == ')')
			{
				int temp = 0;
				if (st.top() >= 0)//숫자가 들어있으면
				{
					while (st.top() >= 0)//안에 있는 숫자들을 더함
					{
						temp += st.top();
						st.pop();
					}
					if (st.top() == -1)//괄호가 스택에 있으면 계산해서 스택에 넣어줌.
					{
						st.pop();
						st.push(temp * 2);
						i++;
					}
				}
				else if (st.top() == -1)
				{
					st.pop();
					st.push(2);
					i++;
				}

				continue;
			}
			if (s[i] == ']')
			{
				int temp = 0;
				if (st.top() >= 0)
				{
					while (st.top() >= 0)//안에 있는 숫자들을 더해서 스택에 넣어줌.
					{
						temp += st.top();
						st.pop();
					}
					if (st.top() == -2)
					{
						st.pop();
						st.push(temp * 3);
						i++;
					}
				}
				else if (st.top() == -2)
				{
					st.pop();
					st.push(3);
					i++;
				}
				continue;
			}
		}
		while (!st.empty())
		{
			result += st.top();
			st.pop();
		}
		printf("%d", result);
	}
	else
		printf("0");
}
