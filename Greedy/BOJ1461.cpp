#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(void)
{
	int n, m;
	int i;
	int book[10000];
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%d", &book[i]);
	sort(book, book + n);
	int sum = 0;
	int plusindex;
	for (i = 0; i < n; i++)
	{
		if (book[i] > 0)
		{
			plusindex = i;
			break;
		}
	}
	for (i = 0; i < plusindex; i=i + m)//책이 음수쪽에 있을때 갔다가 돌아오는 이동거리(한번에 m개씩 옮긴다)
	{
		sum += -1 * book[i]*2;
	}
	for (i = n - 1; i >= plusindex; i=i - m)//책이 양수쪽에 있을 때 갔다가 돌아오는 이동거리
	{
		sum += book[i]*2;
	}
	if (book[0] * (-1) > book[n - 1])//마지막에는 굳이 0으로 돌아올 필요가 없기 때문에 음수중에 가장 작은값과 
		sum += book[0];//양수중에 가장 큰 값의 절대값을 비교하여 더 큰쪽을 빼준다.
	else
		sum -= book[n - 1];
	printf("%d", sum);
}
