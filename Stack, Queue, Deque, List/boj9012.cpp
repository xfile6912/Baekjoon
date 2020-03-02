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
	int t;//테스트케이스의 수
	stack<char> st;
	string s;//괄호 문자열
	scanf("%d", &t);
	int i, j;
	int flag = 1;//0이면 순회가 끝나기 전에 잘못된 문자열을 찾음.
	for (i = 0; i < t; i++)
	{
		flag = 1;
		cin >> s;
		for (j = 0; j < s.size(); j++)
		{
			if (s[j] == '(')//여는 괄호이면 스택에 집어넣어줌.
				st.push('(');
			if (s[j] == ')')//닫는 괄호이면 스택에서 여는 괄호를 pop해줌
			{
				if(!st.empty())
					st.pop();
				else//닫는 괄호가 들어왔는데 스택에 아무것도 없으면 잘못된 괄호 문자열이다.
				{
					flag = 0;
					printf("NO\n");
					break;
				}

			}
		}
		if (flag == 1)
		{
			if (!st.empty())//문자열을 다 순회했는데 스택에 여는 문자열이 남아있으면 잘못된 괄호 문자열이다.
				printf("NO\n");
			else//다 순회하고 스택이 비어있으면 올바른 괄호 문자열이다.
				printf("YES\n");
		}
		while (!st.empty())//다음 테스트케이스를위해 스택을 비워줌
			st.pop();
	}
}
