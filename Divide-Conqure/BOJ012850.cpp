#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define mod 1000000007


int arr[8][8] = {	{0, 1, 1, 0, 0, 0, 0, 0},
					{1, 0, 1, 1, 0, 0, 0, 0},
					{1, 1, 0, 1, 1, 0, 0, 0},
					{0, 1, 1, 0, 1, 1, 0, 0},
					{0, 0, 1, 1, 0, 1, 0, 1},
					{0, 0, 0, 1, 1, 0, 1, 0},
					{0, 0, 0, 0, 0, 1, 0, 1},
					{0, 0, 0, 0, 1, 0, 1, 0},
};

vector<vector<long long> > multiply(vector<vector<long long> >a, vector<vector<long long> >b)
{
	int i, j, k;
	vector<vector<long long> > result(8, vector<long long>(8, 0));
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			for (k = 0; k < 8; k++)
			{
				result[i][k] += a[i][j] * b[j][k];
				result[i][k] %= mod;
			}
		}
	}
	return result;
}


vector<vector<long long> > square(vector<vector<long long> >map,long long n)
{
	vector<vector<long long> > result(8, vector<long long>(8, 0));
	if (n == 1)
		return map;
	if (n == 2)
		return multiply(map, map);
	if (n % 2 == 1)
	{
		result = square(map, n - 1);
		return multiply(result, map);
	}
	else
	{
		result = square(map, n / 2);
		return multiply(result, result);
	}
}
//행렬의 n제곱은 n번 이동하여 i에서 j까지 갈 수 있는 경로의 수
int main(void)
{
	vector<vector<long long> > map(8, vector<long long>(8, 0));
	vector<vector<long long> > result(8, vector<long long>(8, 0));
	long long n;
	int i, j;
	cin >> n;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			map[i][j] = arr[i][j];
		}
	}
	result = square(map, n);
	printf("%d", result[0][0]);
}
