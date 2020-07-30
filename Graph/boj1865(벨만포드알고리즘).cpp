#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

int main(void)
{
	int testCase;
	int n, m, w;
	scanf("%d", &testCase);
	for (int t = 0; t < testCase; t++)
	{
		scanf("%d %d %d", &n, &m, &w);
		vector<vector<int> > info(2 * m + w, vector<int>(3, 0));
		vector<long long> totalcost(n + 1, 2147483647);
		totalcost[1] = 0;
		for (int i = 0; i < 2 * m; i = i + 2)//도로는 방향이 없으므로.
		{
			scanf("%d %d %d", &info[i][0], &info[i][1], &info[i][2]);
			info[i + 1][0] = info[i][1];
			info[i + 1][1] = info[i][0];
			info[i + 1][2] = info[i][2];
		}
		for (int i = 2 * m; i < 2 * m + w; i++)
		{
			scanf("%d %d %d", &info[i][0], &info[i][1], &info[i][2]);
			info[i][2] = 0 - info[i][2];//웜홀에서는 음수시간만큼 걸림.
		}
		int i, j, k;
		int flag = 0;
		for (i = 1; i <= n; i++)//벨만포드 알고리즘.
		{
			for (j = 0; j < 2 * m + w; j++)
			{
				if (totalcost[info[j][1]] > totalcost[info[j][0]] + info[j][2])
					totalcost[info[j][1]] = totalcost[info[j][0]] + info[j][2];
			}
		}
		for (j = 0; j < 2 * m + w; j++)//음수사이클이 있는지 없는지 체크
		{
			if (totalcost[info[j][1]] > totalcost[info[j][0]] + info[j][2])
				flag = 1;
		}
		if (flag == 1)//음수사이클이 있음.
			printf("YES\n");
		else
			printf("NO\n");
	}

}
