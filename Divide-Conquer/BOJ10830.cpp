#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int n;

vector<vector<long long> > multiply(vector<vector<long long> > a, vector<vector<long long> > b, int m)
{
	vector<vector<long long> > arr(n, vector<long long>(n, 0));
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				arr[i][k] += a[i][j] * b[j][k];
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			arr[i][j] %= 1000;
		}
	}
	return arr;
}
vector<vector<long long> > square(vector<vector<long long> > a, long long b, int m)
{
	vector<vector<long long> > arr(2, vector<long long>(2, 0));
	if (b == 1)
		return a;
	if (b == 2)
	{
		return multiply(a, a, m);
	}
	if (b % 2 == 0)
	{
		arr = square(a, b / 2, m);
		return multiply(arr, arr, m);
	}
	else
	{
		arr = square(a, b - 1, m);
		return multiply(arr, a, m);
	}
}


int main(void)
{

	long long b;
	cin >> n>>b;
	vector<vector<long long> > result(n, vector<long long>(n, 0));
	vector<vector<long long> > arr(n, vector<long long>(n, 0));

	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	result = square(arr, b, 1000);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			result[i][j] %= 1000;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
}
