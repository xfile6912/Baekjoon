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
	scanf("%d", &n);
	int i;
	stack<vector<int> > st;
	vector<vector<int> > info(n, vector<int> (2,0));//[0]은 높이, [1]은 인덱스
	vector<int> result(n, 0);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &info[i][0]);
		info[i][1] = i;
	}
	st.push(info[n-1]);
	for (i = n - 2; i >= 0; i--)//오른쪽에서부터 순서대로 스택에 넣어줌.
	{
		if (st.top()[0] < info[i][0])//만약에 현재 송전탑이 더 높다면
		{
			while (!st.empty() && st.top()[0]<info[i][0])//스택안에 있는 송전탑중에 현재 송전탑보다 더 낮은것들은 다 신호가 현재 송전탑으로 감.
			{
				result[st.top()[1]] = i+1;
				st.pop();
			}
		}
		st.push(info[i]);
	}
	while (!st.empty()) {
		result[st.top()[1]] = 0;
		st.pop();
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", result[i]);
	}
}
