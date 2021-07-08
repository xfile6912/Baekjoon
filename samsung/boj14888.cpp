#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;


int n;
vector<int> number(11, 0);
int op[4];
int min_num=1000000000;
int max_num= -1000000000;
int cal(int a, int b, int oper)
{
	if (oper ==0)
	{
		return a + b;
	}
	else if (oper == 1)
	{
		return a - b;
	}
	else if (oper == 2)
	{
		return a * b;
	}
	else
	{
		if (a < 0)
		{
			return -((-a) / b);
		}
		else
		{
			return a / b;
		}
	}
}

void solution(int result, int cnt)
{
	if (cnt == n-1)
	{
		min_num = min(min_num, result);
		max_num = max(max_num, result);
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (op[i] > 0)
			{
				op[i]--;
				solution(cal(result, number[cnt+1], i), cnt+1);
				op[i]++;
			}
		}
	}
}

int main(void)
{

	scanf("%d", &n);
	int i;

	for (i = 0; i < n; i++)
		scanf("%d", &number[i]);
	scanf("%d %d %d %d", &op[0], &op[1], &op[2], &op[3]);
	solution(number[0], 0);
	printf("%d\n", max_num);
	printf("%d\n", min_num);
}
