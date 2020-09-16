#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
string expression;
vector<int> number;//숫자
vector<char> op;//operator
int result = -2147483648;
void dfs(int flag,int start)//0 괄호가 없는 경우, 1 괄호가 있는 경우
{
	int i;
	if (start >= expression.length())
	{
		int temp = number[0];
		for (i = 0; i < op.size(); i++)
		{
			if (op[i] == '+')
			{
				temp += number[i + 1];
			}
			else if (op[i] == '-')
			{
				temp -= number[i + 1];
			}
			else
			{
				temp *= number[i + 1];
			}
		}
		if (temp == 408)
			printf("");
		result = max(temp, result);
		return;
	}

	if (flag == 0 || start+1==expression.length())//괄호가 없는 경우
	{
		number.push_back(expression[start]-'0');
		if (start + 1 != expression.length())
		{
			op.push_back(expression[start+1]);
			dfs(0, start + 2);
			dfs(1, start + 2);
			op.pop_back();
		}
		else
		{
			dfs(0, start + 1);
		}
		number.pop_back();
	}
	else//괄호가 있는 경우
	{
		if (expression[start + 1] == '+')
		{
			number.push_back(expression[start] - '0' + expression[start + 2] - '0');
			if (start + 3 != expression.length())
			{
				op.push_back(expression[start + 3]);
				dfs(0, start + 4);
				dfs(1, start + 4);
				op.pop_back();
			}
			else
			{
				dfs(0, start + 3);
			}
			number.pop_back();
		}
		else if (expression[start + 1] == '-')
		{
			number.push_back(expression[start] - '0' - (expression[start + 2] - '0'));
			if (start + 3 != expression.length())
			{
				op.push_back(expression[start + 3]);
				dfs(0, start + 4);
				dfs(1, start + 4);
				op.pop_back();
			}
			else
			{
				dfs(0, start + 3);
			}
			number.pop_back();
		}
		else
		{

			number.push_back((expression[start] - '0') * (expression[start + 2] - '0'));
			if (start + 3 != expression.length())
			{
				op.push_back(expression[start + 3]);
				dfs(0, start + 4);
				dfs(1, start + 4);
				op.pop_back();
			}
			else
			{
				dfs(0, start + 3);
			}
			number.pop_back();
		}
	}
}

int main(void)
{
	int n = 0;
	cin >> n;
	cin >> expression;
	dfs(0, 0);
	dfs(1, 0);
	printf("%d", result);
}
