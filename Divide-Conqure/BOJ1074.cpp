#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

long long cnt = 0;
long long r, c;
void visit(long long n, long long y,long long x)
{
	long long temp;
	if (n == 2)
	{
		if (r == y && x == c)
		{
			cout << cnt << endl;
			return;
		}
		cnt++;
		if (r == y && x+1 == c)
		{
			cout << cnt << endl;
			return;
		}
		cnt++;
		if (r == y+1 && x == c)
		{
			cout << cnt << endl;
			return;
		}
		cnt++;
		if (r == y+1 && x+1 == c)
		{
			cout << cnt << endl;
			return;
		}
		cnt++;
		return;
	}
	visit(n / 2, y, x);
	visit(n / 2, y, x+n/2);
	visit(n / 2, y+n/2, x);
	visit(n / 2, y+n/2, x+n/2);
}


int main(void)
{
	int n;
	long long temp = 1;
	int temp1 = 0;
	int i;

	cin >> n>> r >> c;
	for (i = 0; i < n; i++)
	{
		temp *= 2;
	}
	visit(temp, 0, 0);


}	
