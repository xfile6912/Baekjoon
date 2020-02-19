#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct node {
	int key;
	int fromi;
	int fromj;
}NODE;
NODE dyna[1001][1001];
int main(void)
{
	char a[1001];
	char b[1001];
	//int dyna[1001][1001];
	char result[1000];
	int lcs;
	int tempi;
	int i, j;
	int anum = 0;
	int bnum = 0;
	scanf("%s", a);
	scanf("%s", b);
	for (i = 0; a[i] != '\0'; i++);//calculate array a's length
	anum = i;
	for (i = anum; i > 0; i--)
		a[i] = a[i - 1];
	for (i = 0; b[i] != '\0'; i++);//calculate array b's length
	bnum = i;
	for (i = bnum; i > 0; i--)
		b[i] = b[i - 1];
	for (i = 0; i < anum; i++)
	{
		dyna[i][0].key = 0;
	}
	for (j = 0; j < bnum; j++)
	{
		dyna[0][j].key = 0;
	}
	for (i = 1; i <= anum; i++)
	{
		for (j = 1; j <= bnum; j++)
		{
			if (a[i] == b[j])
			{
				dyna[i][j].key = dyna[i - 1][j - 1].key + 1;//lcs
				dyna[i][j].fromi = i - 1;//어디로부터 왔는지
				dyna[i][j].fromj = j - 1;
			}
			else
			{
				if (dyna[i - 1][j].key > dyna[i][j - 1].key)
				{
					dyna[i][j].key = dyna[i - 1][j].key;//lcs
					dyna[i][j].fromi = i - 1;//어디로부터 왔는지
					dyna[i][j].fromj = j;
				}
				else
				{
					dyna[i][j].key = dyna[i][j - 1].key;//lcs
					dyna[i][j].fromi = i;//어디로부터 왔는지
					dyna[i][j].fromj = j - 1;
				}
			}
		}
	}
	lcs = dyna[anum][bnum].key;
	printf("%d\n", lcs);
	i = anum;
	j = bnum;
	while (1)
	{
		if (dyna[i][j].key == dyna[dyna[i][j].fromi][dyna[i][j].fromj].key)
		{
			tempi = i;
			i = dyna[i][j].fromi;
			j = dyna[tempi][j].fromj;
		}
		else
		{
			result[lcs--] = a[i];
			tempi = i;
			i = dyna[i][j].fromi;
			j = dyna[tempi][j].fromj;
		}
		if (lcs == 0)
			break;
	}
	lcs = dyna[anum][bnum].key;
	for (i = 1; i <= lcs; i++)
		printf("%c", result[i]);
}
