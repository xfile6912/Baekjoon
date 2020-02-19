#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

vector<int> tree(100001, 0);
vector<int> in(100001, 0);
vector<int> pre(100001, 0);
vector<int> post(100001, 0);
int index = 1;

void maketree(int start,int end,int poststart, int postend)
{
  //postorder의 경우 가장 마지막에 루트가 있음. 이를 이용하여 루트를 찾은 후 인오더에서 루트의 인덱스를 찾아서 트리를 만들어줌.
	int root;
	root = post[postend];
	int i,j;
	int flag=1;
	if (start > end)
		return;
	int mid;
	int postmid;
	for (i = start; i <= end; i++)
	{
		if (in[i] == root)
			break;
	}
	mid = i;
	postmid = poststart + mid - start;
	pre[index++] = root;
	if (start == end)
		return;
	maketree(start, mid - 1,poststart,postmid-1);
	maketree(mid + 1, end,postmid,postend-1);
}

int main(void)
{
	int n;
	scanf("%d", &n);
	int i;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &in[i]);
	}
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &post[i]);
	}
	maketree(1, n,1,n);
	for (i = 1; i <= n; i++)
		printf("%d ", pre[i]);
	printf("\n");
}	


