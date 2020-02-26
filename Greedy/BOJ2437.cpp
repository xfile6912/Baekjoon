#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
using namespace std;

int main(void)
{
	int n;
	int arr[1000];
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	int number = 0;//만들수 있는 숫자.
	if (arr[0] == 1)
		number = 1;
	else
	{
		printf("1\n");
		return 0;
	}
	i = 1;
	while (i<n)
	{
		if (arr[i] > number+1)
			break;
		number = number + arr[i];
		i++;
	}
	printf("%d\n", number + 1);
}
