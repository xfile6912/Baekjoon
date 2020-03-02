#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<string>
#include <vector>
#include<algorithm>
#include <stack>
using namespace std;


int main(void)
{
	int n;
	stack<char> final;//전체답 집어넣는 스택;
	stack<char> oper;//연산자들만 집어넣는 스택
	string s;
	cin >> s;
	int i, j;
	for (i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')//열린 괄호이면 무조건 스택에 넣어줌.
		{
			oper.push(s[i]);
		}
		else if (s[i] == '*' || s[i] == '/' )//연산자 우선순위가 높은 연산자라면 해당 연산자와 같은 우선순위의 연산자들을 
		{//연산자스택에서 팝하고 해당연산자를 연산자 스택에 넣어준다.
			while (!oper.empty() &&(oper.top() == '*' || oper.top() == '/'))
			{
				final.push(oper.top());
				oper.pop();
			}
			oper.push(s[i]);
		}
		else if (s[i] == '+' || s[i] == '-')//연산자 우선순위가 낮은 연산자라면
		{//해당 연산자와 같거나 높은 우선순위의 연산자들을 연산자 스택에서 팝하고 해당 연산자를 연산자 스택에 넣어준다.
			
			while (!oper.empty() && (oper.top() == '*' || oper.top() == '/'||oper.top() == '+' || oper.top() == '-'))
			{
				final.push(oper.top());
				oper.pop();
			}
			oper.push(s[i]);
		}
		else if (s[i] == ')')//만약 닫는 괄호라면 연산자스택안에있는것들을 팝한 순서대로 전체답 스택에 집어 넣어줌.
		{
			while (oper.top() != '(')
			{
				final.push(oper.top());
				oper.pop();
			}
			oper.pop();//마지막으로 닫는 괄호를 연산자 스택에서 팝해줌
		}
		else//만약 피연산자라면 바로바로 전체답 스택에 넣어줌;
		{
			final.push(s[i]);
		}
	}
	while (!oper.empty())//마지막으로 연산자스택에 있는것들을 모두 전체답 스택에 넣어줌.
	{
		final.push(oper.top());
		oper.pop();
	}
	vector<char> result;
	while (!final.empty())
	{
		result.push_back(final.top());
		final.pop();
	}
	for (i = result.size() - 1; i >= 0; i--)
		printf("%c", result[i]);
}
