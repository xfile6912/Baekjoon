#include <stdio.h>

int main(void)
{
	int n;
	int temp;
	int arry[1000];
	int i,j;
	int dp[1000];
	scanf("%d", &n);
	for (i = 0; i < n; i++)//dp배열 초기화
		dp[i] = -1;
	dp[0] = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arry[i]);
	}
	for (i = 0; i < n; i++)
	{
		temp = arry[i];
		for (j = 1; j <= temp && i + j < n; j++)//현재위치 i에서 arry[i]이하만큼 점프 하는경우 따짐
		{
			if (dp[i + j] == -1&& dp[i]!=-1)//dp[i+j]가 -1인 경우 방문 못했으므로 바꾸어줌, dp[i]가 -1인 경우는 i번째 위치에 도달하지 못했기 때문에 고려할 필요 없음.
			{
				dp[i + j] = dp[i] + 1;
			}
		}
		if (i + j == n)
			break;
	}
		printf("%d ", dp[n-1]);
}
