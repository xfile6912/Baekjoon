#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int n, m;
const int mod = 1000000007;

vector<vector<long long> >multiply(vector<vector<long long> > a, vector<vector<long long> > b)
{
	vector<vector<long long> >result(n, vector<long long>(n, 0));
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				result[i][k] += a[i][j] * b[j][k];
				result[i][k] %= mod;
			}
		}
	}
	return result;
}
vector<vector<long long> > square(vector<vector<long long> >map, int d)
{
	vector<vector<long long> >result(n, vector<long long>(n, 0));
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
//n번 이동하였을 때의 경로의 수는 행렬을 n번 제곱한 것과 같음. 
int main(void)
{
	
	scanf("%d %d", &n, &m);
	int d;
	int temp1, temp2;
	vector<vector<long long> >map(n, vector<long long>(n, 0));
	vector<vector<long long> >result(n, vector<long long>(n, 0));
	int i, j;
	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &temp1, &temp2);
		map[temp1 - 1][temp2 - 1] = 1;
		map[temp2 - 1][temp1 - 1] = 1;
	}
	cin >> d;
	result = square(map, d);

	cout<<result[0][0];
}
