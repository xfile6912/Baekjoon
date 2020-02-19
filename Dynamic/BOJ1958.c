#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

string a, b, c;

int dp[101][101][101];


int main()
{
	cin >> a >> b >> c;
	int an, bn, cn;
	an = a.size();
	bn = b.size();
	cn = c.size();
	int i, j, k;
	for (i = 0; i <= an; i++)
	{
		for (j = 0; j <= bn; j++)
		{
			for (k = 0; k <= cn; k++)
			{
				if (i == 0 || j == 0 || k == 0)
					dp[i][j][k] = 0;
				else
				{
					if (a[i-1] == b[j-1] && b[j-1] == c[k-1])
						dp[i][j][k] = dp[i - 1][j - 1][k - 1]+1;
					else
					{
						int temp;
						temp = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
						dp[i][j][k] = temp;
					}
				}
			}
		}
	}
	printf("%d", dp[an][bn][cn]);
}
