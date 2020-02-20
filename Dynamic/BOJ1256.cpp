#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;


long long combination[201][201];

void solved(int n, int m, long long k)
{
	if (k > combination[n + m][n])
	{
		printf("-1");
		return;
	}
	if (n == 0)
	{
		while (m != 0)
		{
			printf("z");
			m--;
		}
		return;
	}
	if (m == 0)
	{
		while (n != 0)
		{
			printf("a");
			n--;
		}
		return;
	}
	if (combination[n - 1 + m][n - 1] >= k)//a n-1개와 z m개를 가지고 k번째 단어를 만들수 있다면 앞에 a를 붙이고 이를 가지고 k번 째 단어를 만들어준다. 
	{
		printf("a");
		solved(n - 1, m, k);
	}
	else//만들 수 없다면 앞에 a가 들어갔을 경우 만들 수 있는 단어의 수를 k에서 빼주고 앞에 z를 붙힌다.
	{
		printf("z");
		solved(n, m - 1, k - combination[n - 1 + m][n - 1]);
	}
}


int main()
{
	int n, m;
	long long k;
	scanf("%d %d %lld", &n, &m, &k);
	int i, j;
	for (i = 0; i < 201; i++)
	{
		combination[i][0] = 1;
		for (j = 1; j < i; j++)
		{
			combination[i][j] = combination[i - 1][j - 1] + combination[i - 1][j];//단어의 수 계산
			if (combination[i][j] > 1000000000)
				combination[i][j] = 1000000000;
		}
		combination[i][i] = 1;
	}
	solved(n, m, k);
}
