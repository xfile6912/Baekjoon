#include <stdio.h>
int left[2000];
int right[2000];
int n;
int dp[2001][2001];
int max(int i, int j)
{
	if (i > j)
		return i;
	else
		return j;
}

int function(int i, int j)
{
	int ret = 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	if (i == n || j == n)
		ret= 0;

	else if (left[i] > right[j])
	{
		ret = right[j];
		ret = ret + function(i, j + 1);
	}
	else
		ret=max(function(i + 1, j + 1), function(i + 1, j));
	dp[i][j] = ret;
	return ret;
}

int main(void)
{
	int i,j;
	int result;
	scanf("%d",&n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &left[i]);
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d", &right[i]);
	}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			dp[i][j] = -1;
	result = function(0, 0);
	printf("%d", result);
}
