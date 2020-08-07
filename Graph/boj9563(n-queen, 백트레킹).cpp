#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

int cnt = 0;
int n;
vector<pair<int, int> > actStack;
void dfs(int y)
{
	int j;
	if (actStack.size()==n)
	{
		cnt++;
		return;
	}
	for (j = 0; j < n; j++)
	{
		int k;
		int flag = 1;//flag가 0이되면 그 다음행에대에서는 확인할 필요가 없어짐.
		for (k = 0; k < actStack.size(); k++)
		{
			if (j == actStack[k].second)//수직선을 통해 공격가능하다면 n queen 아님.
			{
				flag = 0;
				break;
			}
			if (abs(y + 1 - actStack[k].first) == abs(j - actStack[k].second))//대각선을 이용해서 잡힌다면 n Queen에 해당하지 않음
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			actStack.push_back(make_pair(y + 1, j));
			dfs(y + 1);
			actStack.pop_back();
		}
	}
}

int main(void)
{
	int j;
	scanf("%d", &n);
	for (j = 0; j < n; j++)
	{
		actStack.push_back(make_pair(0, j));
		dfs(0);
		actStack.pop_back();
	}
	printf("%d", cnt);
}
