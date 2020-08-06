#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
using namespace std;

int result = 0;
int n, m;
vector<int> answer(8, 0);
vector<int> visited(10, 0);
void solve(int index, int count)
{
	if (index == n)
	{
		if (count != m)
			return;
		result++;
		return;
	}
	for (int i = 0; i <10; i++)
	{
		if (visited[i]) {//수를 사용했다면 0으로 바꾸어줌.
			visited[i] = 0;
			solve(index + 1, count + 1);
			visited[i] = true;
			continue;
		}
		solve(index + 1, count);
	}
}


int main(void)
{

	int temp;

	int i;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d", &temp);
		visited[temp] = 1;//사용해야하는 수를 1로 바꾸어줌.
	}
	solve(0, 0);
	printf("%d", result);
}
