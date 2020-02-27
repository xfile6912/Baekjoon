#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
using namespace std;

int n;
int sensor[10000];
int diff[10000];


int main(void)
{
	int k;
	scanf("%d %d", &n, &k);
	int i, j;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &sensor[i]);
	}
	sort(sensor, sensor + n);
	for (i = 1; i < n; i++)
	{
		diff[i - 1] = sensor[i] - sensor[i - 1];
	}
	sort(diff, diff + n - 1);
	int result = 0;
	if (k == n)
		printf("0");
	else
	{
		for (int i = 0; i < n- k; i++)
		{
			result += diff[i];
		}
		printf("%d", result);
	}
}
