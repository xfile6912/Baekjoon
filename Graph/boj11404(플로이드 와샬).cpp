#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;
int main(void)
{
	int nCity;
	int mBus;
	int from, to, cost;
	scanf("%d", &nCity);
	vector<vector<int> > busInfo(nCity, vector<int>(nCity, 987654321));
	//vector<vector<int> > totalCost(nCity, vector<int>(nCity, 987654321));
	scanf("%d", &mBus);
	for (int i = 0; i < mBus; i++)
	{
		scanf("%d %d %d", &from, &to, &cost);
		if(busInfo[from-1][to-1]>cost)
			busInfo[from-1][to-1] = cost;
	}
	int i, j, k;
	for (i = 0; i < nCity; i++)//플로이드 와샬 알고리즘.
	{
		for (j = 0; j < nCity; j++)
		{
			for (k = 0; k < nCity; k++)
			{
				if (j == k)
					busInfo[j][k] = 0;
				else if (busInfo[j][k] > (busInfo[j][i] + busInfo[i][k]))
					busInfo[j][k] = busInfo[j][i] + busInfo[i][k];
			}
		}
	}
	for (i = 0; i < nCity; i++)
	{
		for (j = 0; j < nCity; j++)
		{
			if (busInfo[i][j] != 987654321)
				printf("%d ", busInfo[i][j]);
			else
				printf("0 ");
		}
		printf("\n");
	}
}
