#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int arr[2187][2187];

int one=0;
int zero=0;
int minusone=0;


void paper(int n, int y, int x)
{
	int i, j;
	int flag = 1;
	int temp;
	for (i = 0; i < n; i++)//모두 동일한 숫자로 이루어져 있는지 검색
	{
		for (j = 0; j < n; j++)
		{
			if (i == 0 && j == 0)
				temp = arr[y + i][x + j];
			if (temp != arr[y + i][x + j])
			{
				flag = 0;
				break;
			}
		}
	}
	if (flag == 1)//이루어져있다면 어떤 숫자인지 보고 카운트 해줌.
	{
		if (temp == -1)
			minusone++;
		else if (temp == 1)
			one++;
		else
			zero++;
	}
	else
	{
		paper(n / 3, y, x);
		paper(n / 3, y, x+n/3);
		paper(n / 3, y, x + n / 3*2);
		paper(n / 3, y + n / 3, x);
		paper(n / 3, y + n / 3, x + n / 3);
		paper(n / 3, y + n / 3, x + n / 3*2);
		paper(n / 3, y + n / 3 * 2, x);
		paper(n / 3, y + n / 3 * 2, x+ n / 3);
		paper(n / 3, y + n / 3 * 2, x+n / 3 * 2);

	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	paper(n, 0, 0);
	printf("%d\n%d\n%d\n", minusone, zero, one);
}	
