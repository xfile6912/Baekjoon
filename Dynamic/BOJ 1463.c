#include <stdio.h>

int findmin(int a, int b, int c)
{
	if (a > b)
	{
		if (b >= c)
			return c;
		else if (c > b)
			return b;
	}
	else
	{
		if (c <= a)
			return c;
		else if (c > a)
			return a;
	}
}

int main()
{
	int a[1000001];
	int n;
	int i;
	int j;
	int val1, val2, val3;
	a[0] = 0;
	a[1] = 0;
	a[2] = 1;
	scanf("%d", &n);
	i = 3;
	for (i = 3; i <= n; i++)
	{
		j = i;
		val1 = -1;
		val2 = -1;
		if (j % 3 == 0)
		{
			val1 = j / 3;
		}
		if (j % 2 == 0)
		{
			val2 = j / 2;
		}
		val3 = j - 1;
		if (val1 != -1 && val2 != -1)
			a[i] = 1 + findmin(a[val1], a[val2], a[val3]);
		else if (val1 == -1 && val2 == -1)
		{
			a[i] = 1 + a[val3];
		}
		else if (val1 == -1)
		{
			a[i] = 1 + findmin(9999999, a[val2], a[val3]);
		}
		else if (val2 == -1)
		{
			a[i] = 1 + findmin(a[val1], 9999999, a[val3]);
		}
	}
	printf("%d\n", a[n]);
}