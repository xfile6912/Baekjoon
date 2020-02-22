#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(void)
{
	int n;
	int distance[100000];
	int price[100000];
	scanf("%d", &n);
	int i;
	long long minprice;
	int temp;
	for (i = 1; i < n; i++)
	{
		scanf("%d", &distance[i]);//이전도시에서 해당 도시까지의 거리
	}
	for (i = 0; i < n; i++)
		scanf("%d", &price[i]);
	minprice = price[0];
	long long sum=0;
	for (i = 1; i < n; i++)
	{
		sum += minprice * distance[i];//지금까지 거쳤던 도시들의 기름들 중에서 싼 가격의 기름을 주입하면 됨.
		if (price[i] < minprice)//새로운 도시에서 이전 기름가격보다 기름이 싸다면 이제부터는 그기름을 주입하면 됨.
			minprice = price[i];
	}
	printf("%lld", sum);
}
