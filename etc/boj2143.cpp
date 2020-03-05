#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(void)
{
	long long t;
	long long n, m;
	long long a[1000];
	long long b[1000];
	vector<long long> asum;
	vector<long long> bsum;
	scanf("%lld", &t);
	scanf("%lld", &n);
	long long i,j;
	for (i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
	}
	for (i = 0; i < n; i++)
	{
		long long sum = 0;
		for (j = i; j < n; j++)
		{
			sum += a[j];
			asum.push_back(sum);
		}
	}//a배열의 모든 부분합들을 asum배열에 저장;
	scanf("%lld", &m);
	for (i = 0; i < m; i++)
	{
		scanf("%lld", &b[i]);
	}
	for (i = 0; i < m; i++)
	{
		long long sum = 0;
		for (j = i; j < m; j++)
		{
			sum += b[j];
			bsum.push_back(sum);
		}
	}//b배열의 모든 부분합들을 bsum배열에 저장;
	sort(asum.begin(), asum.end());
	sort(bsum.begin(), bsum.end());
	long long result = 0;
	for (i = 0; i < asum.size(); i++)
	{
		long long num = 0;
		if (*lower_bound(bsum.begin(), bsum.end(), t - asum[i]) == t - asum[i])
			num = upper_bound(bsum.begin(), bsum.end(), t - asum[i]) - lower_bound(bsum.begin(), bsum.end(), t - asum[i]);
		result += num;
	}
	printf("%lld", result);
}
