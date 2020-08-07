#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
using namespace std;

int result = 0;
int n, m;
vector<int> answer;
vector<int> visited(10, 0);
void solve(int index)
{
	if (index == m)
	{
		int i = 0;
		for (i = 0; i < m; i++)
			printf("%d ", answer[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++)
	{
			answer.push_back(i);
			visited[i] = 1;
			solve(index + 1);
			answer.pop_back();
			visited[i] = 0;
	}
}


int main(void)
{

	int temp;
	int i;
	scanf("%d %d", &n, &m);
	solve(0);
}
