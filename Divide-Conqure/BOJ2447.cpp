#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

char arr[2187][2187];

void print(int n, int flag,int y,int x)
{
	int i, j;
	if (flag == 0)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				arr[i+y][j+x] = ' ';
			}
		}
		return;
	}
	else
	{
		if (n == 1)
		{
			arr[y][x] = '*';
			return;
		}

	}

	print(n / 3, 1,y,x);
	print(n / 3, 1,y,x+n/3);
	print(n / 3, 1,y,x+n/3*2);
	print(n / 3, 1,y+n/3, x);
	print(n / 3, 0,y+n/3, x + n / 3);
	print(n / 3, 1,y+n/3, x+n/3*2);
	print(n / 3, 1,y+n/3*2,x);
	print(n / 3, 1,y+n/3*2, x+n/3);
	print(n / 3, 1,y+n/3*2, x+n/3*2);
}


int main(void)
{
	int n;
	int flag = 1;
	scanf("%d", &n);
	print(n, flag,0,0);
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}	
