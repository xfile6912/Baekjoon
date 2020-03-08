#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

typedef struct node * nodepointer;
typedef struct node {
	int vertex;
	int level;
	int column;
	nodepointer left;
	nodepointer right;
	nodepointer parent;
}NODE;
int n;
vector<NODE> graph[10001];
vector<int> root(10001, 1);
NODE* tree;
vector<int> answer[10001];
void maketree(nodepointer ptr)
{
	int x = ptr->vertex;
	ptr->left = NULL;
	if (graph[x][0].vertex != -1)//왼쪽자식이 있다면
	{
		ptr->left = (&graph[x][0]);
		ptr->left->parent = ptr;
		maketree(ptr->left);
	}
	ptr->right = NULL;
	if (graph[x][1].vertex != -1)//오른쪽자식이 있다면
	{
		ptr->right = (&graph[x][1]);
		ptr->right->parent = ptr;
		maketree(ptr->right);
	}
}

int findroot()
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j < 2; j++)
		{
			if (graph[i][j].vertex != -1)
			{
				root[graph[i][j].vertex] = 0;
			}
		}
	}
	for(i=1; i<=n; i++)
		if (root[i] == 1)
		{
			return i;
		}
}


//ancestor는 노드가 왼쪽 자식일 경우에 노드의 조상들을 거슬러 올라갈 때 처음으로 오른쪽 자식이었던 조상의 부모를 가리킨다.
int dfs(nodepointer ptr, int level, int from, nodepointer ancestor)//dfs를 계산하면 ptr을 루트로하는 트리의 전체노드 수 반환; from이 0이면 부모의 왼쪽자식, 1이면 오른쪽자식
{
	int left = 0;//왼쪽 후손의 수
	int right = 0;//오른쪽 후손의 수

	if (ptr->left!=NULL)//왼쪽자식 노드가 있음
	{
		ptr->left->level = level + 1;//자식노드의 레벨은 부모노드의 레벨+1이다;
		left = dfs(ptr->left, level + 1,0,ancestor);//왼쪽 자식 서브트리의 노드수
	}


	if (from == 1)//노드가 부모의 오른쪽 자식이면 노드의 칼럼은 부모의 칼럼 + 노드의 왼쪽 자식 수+1이다.
	{
		ptr->column = ptr->parent->column + left + 1;
	}
	else
	{
		if (ancestor == NULL)
			ptr->column = left + 1;
		else
			ptr->column = ancestor->column + left + 1;
	}
	answer[ptr->level].push_back(ptr->column);



	if (ptr->right!=NULL)//오른쪽자식 노드가 있음
	{
		ptr->right->level = level + 1;//자식노드의 레벨은 부모노드의 레벨+1이다;
		right = dfs(ptr->right, level + 1,1,ptr);//오른쪽 자식 서브트리의 노드수
	}

	return left+right+1;
}


int main(void)
{

	int v, v1, v2;
	NODE temp;
	scanf("%d", &n);
	int i;
	for (i = 1; i <= n; i++)//트리에 정점들 넣어줌;
	{
		scanf("%d %d %d", &v, &v1, &v2);
		temp.vertex = v1;
		temp.level = 0;
		temp.column = 0;
		graph[v].push_back(temp);

		temp.vertex = v2;
		temp.level = 0;
		temp.column = 0;
		graph[v].push_back(temp);
	}
	NODE* newnode = (NODE*)malloc(sizeof(NODE));
	int root = findroot();
	newnode->vertex = root;
	newnode->level = 1;
	newnode->column = 0;
	tree = newnode;
	maketree(tree);
	
	dfs(tree, 1,-1,NULL);
	int maxvalue=0;
	int maxindex=0;
	for (i = 1; i <= n; i++)
	{
		if (answer[i].size() != 0)
		{
			int temp=answer[i].back() - answer[i][0];
			if (maxvalue < temp)
			{
				maxvalue = temp;
				maxindex = i;
			}

		}
	}
	if (maxvalue == 0)//답이 루트노드인 경우
		printf("1 1");
	else
		printf("%d %d", maxindex, maxvalue+1);
}
