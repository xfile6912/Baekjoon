#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
using namespace std;

int main(void)
{
	int n, k;
	int order[100];
	vector<int> plug;
	scanf("%d %d", &n, &k);
	int i, j;
	for (i = 0; i < k; i++)
	{
		scanf("%d", &order[i]);
	}
	int plugindex;
	int p;
	int result = 0;
	int temp;
	for (i = 0; i < k; i++)
	{
		int flag = 0;
		for (j = 0; j < plug.size(); j++)
		{
			if (plug[j] == order[i])
				flag = 1;
		}
		if (flag == 1)
			continue;
		if (plug.size() < n)
		{
			plug.push_back(order[i]);
		}
		else
		{
			temp = i;//현재 플러그에 꽂혀있는 것들 중에 다음에 해당 플러그를 사용하게 되는 순서 중 가장 나중인 값 저장.
			for (j = 0; j < n; j++)
			{
				for (p = i; p < k; p++)
				{
					if (order[p] == plug[j])
					{
						if (p > temp)//가장 나중에 사용하게 되는 것을 뽑아준다.
						{
							temp = p;
							plugindex = j;
						}
						break;
					}
				}
				if (p == k)//만약에 j번재 플러그를 아무리 순서가 지나도 다시 사용하지 않는다면 이 플러그를 빼주면 된다.
				{
					plugindex = j;
					break;
				}
			}
			plug[plugindex] = order[i];//플러그 빼준자리에 새로 플러그를 꽂아줌.
			result++;
		}
	}
	printf("%d", result);
}
