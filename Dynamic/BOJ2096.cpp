#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;


int first[3];
int mindp[3];
int mintemp[3];
int maxtemp[3];
int maxdp[3];
int n;
int main(void)
{
	scanf("%d", &n);
	int i;
	scanf("%d %d %d", &first[0], &first[1], &first[2]);
	mindp[0] = first[0];
	mindp[1] = first[1];
	mindp[2] = first[2];
	maxdp[0] = first[0];
	maxdp[1] = first[1];
	maxdp[2] = first[2];
	for (i = 1; i < n; i++)
	{
		scanf("%d %d %d", &first[0], &first[1], &first[2]);
		mintemp[0] = min(mindp[0], mindp[1])+first[0];
		maxtemp[0] = max(maxdp[0], maxdp[1])+first[0];
		mintemp[1] = min(mindp[0], min(mindp[1],mindp[2]))+first[1];
		maxtemp[1] = max(maxdp[0], max(maxdp[1], maxdp[2])) + first[1];
		mintemp[2] = min(mindp[1], mindp[2]) + first[2];
		maxtemp[2] = max(maxdp[1], maxdp[2]) + first[2];
		mindp[0] = mintemp[0];	mindp[1] = mintemp[1];	mindp[2] = mintemp[2];
		maxdp[0] = maxtemp[0];	maxdp[1] = maxtemp[1];	maxdp[2] = maxtemp[2];
	}
	printf("%d %d", max(maxdp[0], max(maxdp[1], maxdp[2])), min(mindp[0], min(mindp[1], mindp[2])));
}
