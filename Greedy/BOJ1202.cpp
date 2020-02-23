#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
using namespace std;

bool compare(vector<int> a,vector<int> b)
{
	return a[1] < b[1];
}

int main(void)
{
	int n, k;
	
	
	scanf("%d %d", &n, &k);
	vector<vector<int> > jewel(n, vector<int>(2, 0));//[0]은 보석의 가치//[1]은 보석의 무게
	vector<int> bag(k,0);//가방이 견딜수 있는 무게
	priority_queue<vector<int> > q;
	int i, j;
	long long result=0;
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &jewel[i][1], &jewel[i][0]);
	}
	for (i = 0; i < k; i++)
	{
		scanf("%d", &bag[i]);
	}
	sort(jewel.begin(), jewel.end(),compare);//보석의 무게가 작은순으로 정렬
	sort(bag.begin(), bag.end());//가방의 무게가 작은순으로 정렬
	int cnt = 0;
	for (i = 0; i < k; i++)
	{
		for (j = cnt; j < n; j++)
		{
			if (bag[i] >= jewel[j][1])//가방이 버틸수 있는 무게보다 작거나 같은 보석을 다 큐에집어넣음;
				q.push(jewel[j]);
			else
				break;
		}
		cnt = j;
		if (!q.empty())
		{
			result += q.top()[0];//큐에서 보석의 가치가 가장 큰 것을 가방에 집어넣어줌.
			q.pop();
		}
		
	}
	cout<<result;
}
