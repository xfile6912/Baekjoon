#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

char arr[64][64];

void quadtree(int n, int y, int x)
{
	int flag = 1;
	int i, j;
	char temp;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == 0 && j == 0)
				temp = arr[y + i][x + j];
			else if (arr[y + i][x + j] != temp)
			{
				flag = 0;
				break;
			}

		}
	}

	if (flag == 1)
	{
		printf("%c", temp);
	}
	else
	{
		printf("(");
		quadtree(n / 2, y, x);
		quadtree(n / 2, y, x+n/2);
		quadtree(n / 2, y+n/2, x);
		quadtree(n / 2, y+n/2, x+n/2);
		printf(")");
	}

}

int main(void)
{
	int n;
	scanf("%d", &n);
	int i, j;
	char enter;
	for (i = 0; i < n; i++)
	{
		scanf("%c", &enter);
		for (j = 0; j < n; j++)
		{
			scanf("%c", &arr[i][j]);
		}
	}
	quadtree(n, 0, 0);
	printf("\n");
}	
