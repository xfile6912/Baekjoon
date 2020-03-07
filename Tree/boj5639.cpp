#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
using namespace std;

typedef struct tree* tp;
typedef struct tree {
	int node;
	tp left;
	tp right;
}TREE;
tp head=NULL;

void addtree(int node)
{
	TREE* newnode = (TREE*)malloc(sizeof(TREE));
	newnode->node = node;
	newnode->left = NULL;
	newnode->right = NULL;
	tp ptr;
	if (head == NULL)//만약에 헤드가 널이면 해당 노드는 트리의 루트이다;
	{
		head = newnode;
	}
	else
	{
		ptr = head;
		while (1)//이진검색트리에서 올바른 위치를 찾아서 삽입시켜줌;
		{
			if (ptr->node > node)
			{
				if (ptr->left == NULL)
				{
					ptr->left = newnode;
					break;
				}
				else
				{
					ptr = ptr->left;
				}
			}
			else
			{
				if (ptr->right == NULL)
				{
					ptr->right = newnode;
					break;
				}
				else
				{
					ptr = ptr->right;
				}
			}
		}
	}
}
void postorder(tp ptr)
{
	if (ptr->left != NULL)
		postorder(ptr->left);
	if (ptr->right != NULL)
		postorder(ptr->right);
	printf("%d\n", ptr->node);
}
int main(void)
{
	int node;
	while (scanf("%d", &node) == 1)
	{
		addtree(node);
	}
	postorder(head);
}
