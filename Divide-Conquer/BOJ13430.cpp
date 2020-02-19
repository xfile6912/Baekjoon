#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int n, k;
const int mod = 1000000007;

vector<vector<long long> >multiply(vector<vector<long long> > a, vector<vector<long long> > b)
{
	vector<vector<long long> >result(k, vector<long long>(k, 0));
	int i, j, p;
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < k; j++)
		{
			for (p = 0; p < k; p++)
			{
				result[i][p] += a[i][j] * b[j][p];
				result[i][p] %= mod;
			}
		}
	}
	return result;
}
vector<vector<long long> > square(vector<vector<long long> >map, int d)
{
	vector<vector<long long> >result(k, vector<long long>(k, 0));
	if (d == 1)
		return map;
	if (d == 2)
		return multiply(map, map);
	if (d % 2 == 1)//홀수인경우
	{
		result = square(map, d - 1);
		return multiply(result, map);
	}
	else
	{
		result = square(map, d / 2);
		return multiply(result, result);

	}
}

int main(void)
{

	scanf("%d %d", &k, &n);
	int temp1, temp2;
	k = k + 2;
	vector<vector<long long> >map(k, vector<long long>(k+2, 0));
	int i, j;
	for (i = 0; i < k; i++)
	{
		for (j = 0; j <= i; j++)
		{
			map[i][j] = 1;
		}
	}
	vector<vector<long long> >result(k, vector<long long>(k, 0));

	result = square(map, n);
	cout << result[k - 1][0];

}
