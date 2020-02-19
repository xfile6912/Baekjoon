#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//행렬의 곱을 이용한 피보나치 수열 계산
//f= 0 1
//   1 1

vector<vector<long long> > multiply(vector<vector<long long> > a, vector<vector<long long> > b, int m)
{
	vector<vector<long long> > arr(2, vector<long long>(2, 0));
	arr[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % m;
	arr[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % m;
	arr[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % m;
	arr[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % m;
	return arr;
}
vector<vector<long long> > square(vector<vector<long long> > a, long long n, int m)
{
	vector<vector<long long> > arr(2, vector<long long>(2, 0));
	if (n == 1)
		return a;
	if (n == 2)
	{
		return multiply(a, a, m);
	}
	if (n % 2 == 0)
	{
		arr = square(a, n / 2, m);
		return multiply(arr, arr, m);
	}
	else
	{
		arr = square(a, n - 1, m);
		return multiply(arr, a, m);
	}
}


int main(void)
{
	vector<vector<long long> > result(2, vector<long long>(2, 0));
	vector<vector<long long> > arr(2, vector<long long>(2, 0));
	long long n;
	arr[0][0] = 0;
	arr[0][1] = 1;
	arr[1][0] = 1;
	arr[1][1] = 1;
	cin >> n;
	result = square(arr, n, 1000000007);
	printf("%d", result[0][1]);
}
