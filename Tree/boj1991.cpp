#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
using namespace std;

vector<int> graph[26];

void preorder(int root)
{
	printf("%c", root + 'A');
	if (graph[root][0] != -1)//왼쪽자식이 있다면
		preorder(graph[root][0]);
	if (graph[root][1] != -1)//오른쪽자식이 있다면
		preorder(graph[root][1]);
}
void inorder(int root)
{
	if (graph[root][0] != -1)//왼쪽자식이 있다면
		inorder(graph[root][0]);
	printf("%c", root + 'A');
	if (graph[root][1] != -1)//오른쪽자식이 있다면
		inorder(graph[root][1]);
}
void postorder(int root)
{

	if (graph[root][0] != -1)//왼쪽자식이 있다면
		postorder(graph[root][0]);
	if (graph[root][1] != -1)//오른쪽자식이 있다면
		postorder(graph[root][1]);
	printf("%c", root + 'A');
}

int main(void)
{
	int n;
	char enter;
	char parent, lc, rc;//parent, leftchild, rightchild;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%c", &enter);
		scanf("%c %c %c", &parent, &lc, &rc);
		if(lc!='.')//만약 왼쪽자식이 있으면 트리에 넣어준다.
			graph[parent - 'A'].push_back(lc - 'A');
		else//왼쪽자식이 없으면 -1을 넣어줌(null과 같은 맥락)
			graph[parent - 'A'].push_back(-1);
		if (rc != '.')//만약 오른쪽자식이 있으면 트리에 넣어준다.
			graph[parent - 'A'].push_back(rc - 'A');
		else//오른쪽자식이 없으면 -1을 넣어줌(null과 같은 맥락)
			graph[parent - 'A'].push_back(-1);
	}
	preorder(0);
	printf("\n");
	inorder(0);
	printf("\n");
	postorder(0);
	printf("\n");
}
