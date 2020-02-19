#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define mod 1000;

int n;

vector<vector<int> > multiply(vector<vector<int> >a, vector<vector<int> >b)
{
	int i, j, k;
	vector<vector<int> > result(n, vector<int>(n, 0));
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				result[i][k] += a[i][j] * b[j][k];
				if (result[i][k] != 0 && result[i][k] % 1000 == 0)
					result[i][k] = 1000;
				else
					result[i][k] %= mod;
			}
		}
	}
	return result;
}


vector<vector<int> > square(vector<vector<int> >map,int t)
{
	vector<vector<int> > result(n, vector<int>(n, 0));
	if (t == 1)
		return map;

	if (t == 2)
		return multiply(map, map);
	if (t % 2 == 1)
	{
		result = square(map, t - 1);
		return multiply(result, map);
	}
	else
	{
		result = square(map, t / 2);
		return multiply(result, result);
	}
}

int main(void)
{
	int k;
	int m;
	int a;
	int b;
	vector<vector<int> >map(200, vector<int>(200, 0));
	vector<vector<int> >result(200, vector<int>(200, 0));
	int temp1, temp2;
	cin >> n >> k >> m;
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &temp1, &temp2);
		map[i][temp1-1]++;
		map[i][temp2 - 1]++;
	}
	result = square(map,k);
	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		if (result[a - 1][b - 1] == 0)//m번째에 a에서 b까지 가는 경우가 없으면 life
			printf("life\n");
		else
			printf("death\n");//있으면 death;
	}
}
