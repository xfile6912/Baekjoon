#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
long long n;

bool compare(int x, int y)
{
	return x > y;
}

int main(void)
{
	scanf("%lld", &n);
	vector<long long> a(n, 0);
	vector<long long> b(n, 0);
	vector<long long> c(n, 0);
	vector<long long> d(n, 0);
	vector<long long> ab(n*n, 0);
	vector<long long> cd(n * n, 0);
	long long i, j;
	long long cnt;
	for (i = 0; i < n; i++)
	{
		scanf("%lld %lld %lld %lld", &a[i], &b[i], &c[i], &d[i]);
	}
	cnt = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			ab[cnt] = a[i] + b[j];
			cd[cnt] = c[i] + d[j];
			cnt++;
		}
	}
	sort(ab.begin(), ab.end());
	sort(cd.begin(), cd.end());
	j = 0;
	cnt = 0;
	for (i = 0; i < n * n; i++)
	{
		int cdstart = lower_bound(cd.begin(), cd.end(), -ab[i]) - cd.begin();
		int cdend = upper_bound(cd.begin(), cd.end(), -ab[i]) - cd.begin();
		if (cdstart<n*n && cd[cdstart] == -ab[i])
		{
			cnt += cdend - cdstart;
		}

	}
	printf("%lld", cnt);
}
