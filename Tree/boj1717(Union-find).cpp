#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>

using namespace std;

int find(int x, vector<int> &parent)
{
	if (parent[x] < 0)
	{
		return x;
	}
	else
		return parent[x]=find(parent[x], parent);
}

int main(void)
{
	int n, m;
	int i, order;
	int v1, v2;
	scanf("%d %d", &n, &m);
	vector<int> parent(n + 1, -1);
	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d", &order, &v1, &v2);

		if (order == 0)
		{
			if ((v1=find(v1, parent)) != (v2=find(v2, parent)))//조상이 같지 않은 경우면 union_find tree 수정.
			{
				if (parent[v1] < parent[v2])
				{
					parent[v1] += parent[v2];
					parent[v2]= v1;
				}
				else 
				{
					parent[v2] += parent[v1];
					parent[v1] = v2;
				}
			}
		}
		if (order == 1)
		{
			if (find(v1, parent) == find(v2, parent))//조상이 같은경우면 같은 집합.
				printf("YES\n");
			else
				printf("NO\n");
		}


	}
}
