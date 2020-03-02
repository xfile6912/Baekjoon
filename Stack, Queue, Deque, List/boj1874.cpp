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
	int n;
	int arr[100000];
	stack<int> st;
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	vector<char> answer;
	int index = 0;
	int num = 1;
	while (index < n )
	{
		if (!st.empty() && arr[index] == st.top())//스택이 안비어있고 스택의 탑이 현재 인덱스의 숫자와 같다면 팝해줌.
		{
			answer.push_back('-');
			st.pop();
			index++;
		}
		else//스택에 숫자를 넣어줌.
		{
			if (num == n + 1)//num이 n+1이면 해당 수열을 만들 수 없는것이 되므로 반복문을 종료해줌.
				break;
			answer.push_back('+');
			st.push(num++);//1부터 오름차순으로 넣어줌.
		}
	}
	if (st.empty())
	{
		for (i = 0; i < answer.size(); i++)
		{
			printf("%c\n", answer[i]);
		}
	}
	else
		printf("NO\n");
}
