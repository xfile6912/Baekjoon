#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<vector>
#include<queue>
#include <map>
#include<algorithm>
using namespace std;



int main(void)
{	
	int k, n;
	priority_queue<long long, vector<long long>, greater<long long> > q;
	map <long long , int > check;
	int i;
	long long arr[100];
	scanf("%d %d", &k, &n);
	for (i = 0; i < k; i++)
	{
		scanf("%lld", &arr[i]);
	}
	int cnt = 0;
	for (i = 0; i < k; i++)
		q.push(arr[i]);
	long long result;
	long long maxvalue = arr[k-1];
	while (1)
	{
		result = q.top();
		q.pop();
		cnt++;
		if (cnt == n)
			break;
		for (i = 0; i < k; i++)
		{
			if (q.size() + cnt>= n && result* arr[i] > maxvalue)
				break;
			if (check[result * arr[i]] == 0)
			{
				q.push(result * arr[i]);
				check[result * arr[i]] = 1;
				if (result * arr[i] > maxvalue)
					maxvalue = result * arr[i];
			}
		}
	}
	printf("%lld", result);
}
