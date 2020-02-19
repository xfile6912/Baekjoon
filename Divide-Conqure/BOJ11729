#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;


void hanoi(int from,int mid, int to, int n)
{
	if (n == 1)
	{
		printf("%d %d\n", from, to);
		return;
	}
	hanoi(from,to, mid, n - 1);
	printf("%d %d\n",from, to);
	hanoi(mid,from, to, n - 1);

}


int main(void)
{
	int n;
	scanf("%d", &n);
	int k;
	int i;
	int sum = 1;
	for (i = 0; i < n; i++)//이동 수 계산
	{
		sum *= 2;
	}
	sum--;
	printf("%d\n", sum);
	hanoi(1,2, 3, n);
}	
