#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int info[100000];

int main(void)
{
	int n;
	int i;
	scanf("%d", &n);
	int j;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &info[i]);
	}
	sort(info, info + n);//정렬
	int cnt=0;
	int sum=0;
	int result=0;
	for (i = n - 1; i >= 0; i--)
	{
		cnt++;//로프의 개수
		result = max(result,info[i] * cnt);
		//정렬되어 있으므로 현재 이전에 골랐던 로프들은 다 현재로프의 무게만큼을 들 수 있다.
		//따라서 현재로프의 버틸수 있는 무게 * 로프의 수를 해서 최대값을 찾으면 된다.
		
	}
	printf("%d", result);
}
