#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <iostream>
#include <map>
using namespace std;


string findans(string x, map<string, pair<string, int> > &parent)
{
	if (parent[x].first == x)
	{
		return x;
	}
	else
	{
		return parent[x].first = findans(parent[x].first, parent);
	}
}

int main(void)
{
	int t, f;
	int i, order;
	int v1, v2;
	string a, b;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--)
	{
		map<string, pair<string, int> > parent;
		cin >> f;
		for (i = 0; i < f; i++)
		{
			cin >> a >> b;
			if (parent.find(a) == parent.end())//친구 네트워크 안에 a가 있는지 확인
			{
				parent[a] = make_pair(a, -1);//없으면 본인을 parent로 해서 넣어줌.
			}
			if (parent.find(b) == parent.end())//친구 네트워크 안에 b가 있는지확인 
			{
				parent[b] = make_pair(b, -1);;//없으면 본인을 parent로 해서 넣어줌.
			}
			string ancestora, ancestorb;
			ancestora = findans(a, parent);
			ancestorb = findans(b, parent);
			if (ancestora != ancestorb)
			{
				if (parent[ancestora].second < parent[ancestorb].second)
				{
					parent[ancestora].second += parent[ancestorb].second;// b가 속한 집합이 a가 속한 집합에 속하게 되고 집합의 최종 ancestor가 ancestora가 되고 따라서 집합의 구성원수를 갱신해줌.
					parent[ancestorb].first = ancestora;//b의 조상의 parent는 a의 조상이 됨
					printf("%d\n", 0 - parent[ancestora].second);//집합의 구성원수 출력
				}
				else
				{
					parent[ancestorb].second += parent[ancestora].second;// a가 속한 집합이 b가 속한 집합에 속하게 되고 집합의 최종 ancestor가 ancestorb가 되고 따라서 집합의 구성원수를 갱신해줌.
					parent[ancestora].first = ancestorb;//a의 조상의 parent는 b의 조상이 됨
					printf("%d\n", 0 - parent[ancestorb].second);//집합의 구성원수 출력
				}
			}
			else
			{
				printf("%d\n", 0 - parent[ancestora].second);
			}
		}
	}
}
