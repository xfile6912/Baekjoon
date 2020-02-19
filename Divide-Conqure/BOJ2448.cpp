#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

char arr[10000][10000];
char copy[3][5];

void initcopy()
{
	copy[0][0] = ' '; copy[0][1] = ' '; copy[0][2] = '*'; copy[0][3] = ' '; copy[0][4] = ' ';
	copy[1][0] = ' '; copy[1][1] = '*'; copy[1][2] = ' '; copy[1][3] = '*'; copy[1][4] = ' ';
	copy[2][0] = '*'; copy[2][1] = '*'; copy[2][2] = '*'; copy[2][3] = '*'; copy[2][4] = '*';
}
void star(int n, int flag,int y,int x)
{
	int i, j;
	if (n == 3)
	{
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 5; j++)
			{
				arr[y + i][x + j] = copy[i][j];
			}
		}
		return;
	}
	else
	{
		star(n / 2, 1, y, x + n / 2);
		star(n / 2, 1, y + n / 2, x);
		star(n / 2, 1, y + n / 2, x+n);
	}
}


int main(void)
{
	int n;
	int flag = 1;
	initcopy();
	scanf("%d", &n);
	star(n, flag,0,0);
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n*2; j++)
		{
			if (arr[i][j] == '*')
				printf("%c", arr[i][j]);
			else
				printf(" ");
		}
		printf("\n");
	}
}	
