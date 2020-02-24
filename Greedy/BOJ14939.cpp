#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
using namespace std;

char bulb[10][10];
int n;
char temp[10][10];
int dir[2][5] = { {0,-1,1,0,0}, {0,0,0,1,-1} };
void change(int y, int x)//상하좌우와 자기자신의 전구 상태를 바꾸어줌.
{
	int i;
	int nexty, nextx;
	for (i = 0; i < 5; i++)
	{
		nexty=y+dir[0][i];
		nextx=x+dir[1][i];
		if (nexty >= 0 && nexty < n && nextx >= 0 && nextx < n)
		{
			if (bulb[nexty][nextx] == 'O')
				bulb[nexty][nextx] = '#';
			else
				bulb[nexty][nextx] = 'O';
		}
	}

}

int main(void)
{
	char enter;
	int i, j;
	int result = 987654321;
	int cnt=0;
	n = 10;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%c", &temp[i][j]);
		}
		scanf("%c", &enter);
	}
	for (int k = 0; k < (1<<n); k++)//맨 윗줄의 모든 경우의 수(킬 수도있고 안 킬수도 있음)
	{
		for (i = 0; i < n; i++)//bulb에 처음 입력받았던 배열을 넣어줌.
			for (j = 0; j < n; j++)
				bulb[i][j] = temp[i][j];

		cnt = 0;
		for (i = 0; i < n; i++)//비트마스킹 이용해서 모든 경우의 수 따지는데 만약에 해당 전구자리가 1이면 바꾸어줌(맨 윗줄);
		{
			if ((k >> i) % 2 == 1)
			{
				change(0, i);
				cnt++;
			}

		}


		for (i = 1; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (bulb[i - 1][j] == 'O')//바로 위의 전구가 켜져 있으면 전구를 꺼줌.
				{
					change(i, j);
					cnt++;
				}
			}
		}




		int flag = 1;
		for (i = 0; i < n; i++)//다 검사해서 하나라도 불이 켜져있으면 안됨.
		{
			for (j = 0; j < n; j++)
			{
				if (bulb[i][j] == 'O')
				{
					flag = 0;
					break;
				}
			}
		}
		if(flag==1)//다 불이 꺼져있는 경우에만
			result = min(result, cnt);
	}
	if (result != 987654321)
		printf("%d", result);
	else
		printf("-1");
}
