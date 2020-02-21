#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>

using namespace std;

int main(void)
{
	int n, k;
	int i;
	int cnt = 0;
	scanf("%d %d", &n, &k);
	vector<int> money(n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &money[i]);
	}
	for (i = n - 1; i >= 0; i--)//돈의 가치가 큰것 부터
	{
		if (k >= money[i])
		{
			cnt += k / money[i];//해당 가치의 동전을 이용했을 때 필요한 동전의 개수
			k = k % money[i];//남은 가치;
			if (k == 0)
				break;
		}
	}
	printf("%d", cnt);
}
