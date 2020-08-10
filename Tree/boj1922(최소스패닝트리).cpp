#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<int> x, vector<int> y)
{
	if (x[2] == y[2])
	{
		if (x[1] == y[1])
			return x[0] < y[0];
		return x[1] < y[1];
	}
	return x[2] < y[2];
}
vector<int> ftree(1001, -1);
int findans(int x)
{
	while (ftree[x]>0)
	{
		x = ftree[x];
	}
	return x;
}

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	int total = 0;
	int i, j;
	vector<vector<int> > line(m, vector<int>(3, 0));
	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d", &line[i][0], &line[i][1], &line[i][2]);
	}
	sort(line.begin(), line.end(), compare);
	for (i = 0; i < m; i++)
	{
		if (line[i][0] == line[i][1])//a와 b가 같은경우
			continue;
		int parentv1= findans(line[i][0]);
		int parentv2= findans(line[i][1]);
		if(parentv1==parentv2)//조상이 같으면
			continue;
		if (ftree[parentv1] < ftree[parentv2])
		{
			ftree[parentv2] += ftree[parentv1];
			ftree[parentv1] = parentv2;
		}
		else
		{
			ftree[parentv1] += ftree[parentv2];
			ftree[parentv2] = parentv1;

		}
		total += line[i][2];
	}
	printf("%d", total);
}
