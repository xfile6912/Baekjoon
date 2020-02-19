#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<long long> dp;

int main()
{
	int n;
	scanf("%d", &n);
	int i;
	for (i = 0; i <10; i++)//0~9까지는 감소하는 수이므로 그냥 dp에 넣음
	{
		dp.push_back(i);
	}
	if (n < 10)
	{
		printf("%lld",dp[n]);
		return 0;
	}
	i = 1;
	long long temp;
	int first=0;
	while (1)//index i를 이용해 수를 뽑아 그 수로 만들 수있는 감소하는 수를 순서대로 dp에 집어넣음.
	{
		if (dp[i] == 9876543210)//만들 수있는 최대수는 9876543210이다.
		{
			printf("-1");
			break;
		}
		temp = dp[i];
		if (temp % 10 > first)//dp[i]의 1의 자리에 있는 수가 10의자리로 올라서게 되므로 first가 1의자리 수보다 작으면 dp에 집어넣음.
		{
			dp.push_back(temp * 10 + first);
			first++;
		}
		else
		{
			first = 0;
			i++;
		}
		if (dp.size() - 1 == n)
		{
			printf("%lld", dp[n]);
			break;
		}
	}
}
