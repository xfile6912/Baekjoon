#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>

using namespace std;
int n, m;
int findmax = 0;
vector<vector<int> > info(500, vector<int>(500, 0));
void get1()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m-3; j++)
		{
			int temp = info[i][j] + info[i][j + 1] + info[i][j + 2] + info[i][j + 3];
			if (temp > findmax)
				findmax = temp;
		}
	}
	for (i = 0; i < n-3; i++)
	{
		for (j = 0; j < m; j++)
		{
			int temp = info[i][j] + info[i+1][j] + info[i + 2][j] + info[i + 3][j];
			if (temp > findmax)
				findmax = temp;
		}
	}
}
void get2()
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < m - 1; j++)
		{
			int temp = info[i][j] + info[i + 1][j] + info[i][j + 1] + info[i+1][j+1];
			if (temp > findmax)
				findmax = temp;
		}
	}
}
void get3()
{
	int i, j;
	for (i = 0; i < n - 2; i++)
	{
		for (j = 0; j < m - 1; j++)
		{
			int temp1 = info[i][j] + info[i+1][j] + info[i+2][j] + info[i+2][j+1];
			int temp2 = info[i][j] + info[i][j+1] + info[i+1][j+1] + info[i+2][j+1];
			int temp3 = info[i][j+1] + info[i+1][j+1] + info[i+2][j+1] + info[i+2][j];
			int temp4 = info[i][j] + info[i+1][j] + info[i+2][j] + info[i][j+1];
			if (temp1 > findmax)
				findmax = temp1;
			if (temp2 > findmax)
				findmax = temp2;
			if (temp3 > findmax)
				findmax = temp3;
			if (temp4 > findmax)
				findmax = temp4;
		}
	}
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < m - 2; j++)
		{
			int temp1 = info[i][j] + info[i][j+1] + info[i][j+2] + info[i+1][j];
			int temp2 = info[i+1][j] + info[i+1][j+1] + info[i+1][j+2] + info[i][j];
			int temp3 = info[i + 1][j] + info[i + 1][j + 1] + info[i + 1][j + 2] + info[i][j+2];
			int temp4 = info[i][j] + info[i][j + 1] + info[i][j + 2] + info[i + 1][j+2];
			if (temp1 > findmax)
				findmax = temp1;
			if (temp2 > findmax)
				findmax = temp2;
			if (temp3 > findmax)
				findmax = temp3;
			if (temp4 > findmax)
				findmax = temp4;
		}
	}
}
void get4()
{
	int i, j;
	for (i = 0; i < n - 2; i++)
	{
		for (j = 0; j < m - 1; j++)
		{
			int temp1 = info[i][j] + info[i + 1][j] + info[i + 1][j + 1] + info[i + 2][j + 1];
			int temp2 = info[i][j + 1] + info[i + 1][j + 1] + info[i+1][j] + info[i + 2][j];
			if (temp1 > findmax)
				findmax = temp1;
			if (temp2 > findmax)
				findmax = temp2;
		}
	}
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < m - 2; j++)
		{
			int temp1 = info[i][j + 1] + info[i][j + 2] + info[i + 1][j] + info[i + 1][j + 1];
			int temp2 = info[i][j] + info[i][j + 1] + info[i + 1][j + 1] + info[i + 1][j + 2];
			if (temp1 > findmax)
				findmax = temp1;
			if (temp2 > findmax)
				findmax = temp2;
		}
	}
}
void get5()
{
	int i, j;
	for (i = 0; i < n - 2; i++)
	{
		for (j = 0; j < m - 1; j++)
		{
			int temp1 = info[i][j] + info[i+1][j] + info[i+2][j] + info[i+1][j+1];
			int temp2 = info[i+1][j] + info[i][j+1] + info[i+1][j+1] + info[i+2][j+1];
			if (temp1 > findmax)
				findmax = temp1;
			if (temp2 > findmax)
				findmax = temp2;
		}
	}
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < m - 2; j++)
		{
			int temp1 = info[i][j] + info[i][j+1] + info[i][j+2] + info[i+1][j+1];
			int temp2 = info[i+1][j] + info[i+1][j + 1] + info[i + 1][j + 2] + info[i][j+1];
			if (temp1 > findmax)
				findmax = temp1;
			if (temp2 > findmax)
				findmax = temp2;
		}
	}
}
int main(void)
{
	scanf("%d %d", &n, &m);
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &info[i][j]);
		}
	}
	get1(); get2(); get3(); get4(); get5();
	printf("%d", findmax);

}
