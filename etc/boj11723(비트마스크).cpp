#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int s = 0;
	int option[21];
	int zero = 0;
	for (int i = 1; i < 21; i++)
	{
		option[i] = 1 << (i-1);
	}

	int m;
	scanf("%d", &m);
	char order[10];
	int num;
	for(int i=0; i<m; i++)
	{
		scanf("%s", order);
		if (order[2] == 'd')
		{
			scanf("%d", &num);
			s |= option[num];
		}
		else if (order[0] == 'r')
		{
			scanf("%d", &num);
			s = s & (~option[num]);
		}
		else if (order[0] == 'c')
		{
			scanf("%d", &num);
			if (s & option[num])
				printf("1\n");
			else
				printf("0\n");
		}
		else if (order[0] == 't')
		{
			scanf("%d", &num);
			if (s & option[num])
				s = s & (~option[num]);
			else
				s |= option[num];
		}
		else if (order[0] == 'a')
		{
			s = ~zero;
		}
		else if (order[0] == 'e')
		{
			s = zero;
		}
	}
}
