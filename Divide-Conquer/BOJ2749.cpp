#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

vector<int>fibo(1500000, -1);//피사노 주기 이용.

int fibonacci(long long n)
{
	if (fibo[n] != -1)
		return fibo[n];
	fibo[n] = ((long long)fibonacci(n-1) + fibonacci(n-2))%1000000;
	return fibo[n];
}


int main(void)
{
	long long n;
	cin >> n;
	n = n % 1500000;
	

	if (n < 3)
	{
		fibo.push_back(0);
		fibo.push_back(0);
		fibo.push_back(0);
	}
	fibo[0] = 0;
	fibo[1] = 1;
	fibo[2] = 1;
	
	cout << fibonacci(n) << endl;
}	


