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
	stack<char> st;
	char input[100];//문자열
	int isize;//문자열의 사이즈
	int i;
	while (1)
	{
		int flag = 1;//균형잡힌 문자열인지 확인//1이면 균형잡힌 문자열//0이면 잘못된문자열
		for (i = 0; ; i++)
		{
			scanf("%c", &input[i]);
			if (input[i] == '\n')
			{
				isize = i-1;
				input[i] = '\0';//enter가 들어오면 널문자로 바꾸어줌.
				break;
			}
		}
		if (isize == 0)
			break;
		///////////////
		for (i = 0; i < isize; i++)
		{
			if (input[i] == '(')//들어온것이 열린괄호이면 스택에 넣어준다.
				st.push('(');
			else if (input[i] == '[')//들어온것이 열린괄호이면 스택에 넣어준다.
				st.push('[');
			else if (input[i] == ')')
			{
				if (st.empty())//닫는 괄호가 들어왔는데 스택이 비어있으면 잘못된 문자열
				{
					flag = 0;
					break;
				}
				else if (st.top() == '(')//맞게 매칭되어 있으면 pop해줌
				{
					st.pop();
				}
				else//잘못 매칭되어 있으면 잘못된 문자열
				{
					flag = 0;
					break;
				}
			}
			else if (input[i] == ']')
			{
				if (st.empty())//닫는 괄호가 들어왔는데 스택이 비어있으면 잘못된 문자열
				{
					flag = 0;
					break;
				}
				else if (st.top() == '[')//맞게 매칭되어 있으면 pop해줌
				{
					st.pop();
				}
				else//잘못 매칭되어 있으면 잘못된 문자열
				{
					flag = 0;
					break;
				}
			}
		}
		/////////////////
		//문자열을 다 순회함
		if (flag == 0 || !st.empty())//flag가 0이거나 순회가 다끝났는데 스택에 뭔가 남아있으면 균형잡힌 문자열이아님.
		{
			printf("no\n");
			while (!st.empty())
				st.pop();
		}
		else
			printf("yes\n");
	}
}
