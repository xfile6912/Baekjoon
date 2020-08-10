#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ftree(100001, -1);
int findans(int x)
{
	if (ftree[x] < 0)
		return x;
	else
	{
		return ftree[x]=findans(ftree[x]);
	}
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
		scanf("%d %d %d", &line[i][1], &line[i][2], &line[i][0]);
	}
	int max = 0;
	int count = 0;
	sort(line.begin(), line.end());
	for (i = 0; i < m; i++)
	{
		int parentv1 = findans(line[i][1]);
		int parentv2 = findans(line[i][2]);
		if (parentv1 == parentv2)//조상이 같으면
			continue;
		else if (ftree[parentv1] < ftree[parentv2])
		{
			ftree[parentv1] += ftree[parentv2];
			ftree[parentv2] = parentv1;
		}
		else
		{
			ftree[parentv2] += ftree[parentv1];
			ftree[parentv1] = parentv2;
		}
		count++;
		if (count == n - 1)
			break;
		total += line[i][0];
	}
	printf("%d", total);

}
