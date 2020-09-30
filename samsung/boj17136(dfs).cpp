#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int result = 1000000;
vector<vector<int> > board(10, vector<int>(10, 0));
vector<int> paperCount(6, 5);

int test(int n, int y, int x)//nxn 색종이가 들어갈 수 있는지 확인
{
	int i, j;
	int flag = 1;//1이면 해당색종이가 들어갈 수 있고, 0이면 색종이 못들어감.
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (y + i < 10 && x + j < 10 && board[y+i][x+j] == 1)
				continue;
			else
			{
				flag = 0;
				break;
			}
		}
	}
	return flag;//들어갈 수 있으면 1 리턴, 들어갈 수 없으면 0리턴.
}

void change(int value,int n, int y, int x)//(y, y+n), (x, x+n)의 범위를 value값으로 바꾸어주는 역할
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			board[y + i][x + j] = value;
		}
	}
}

void find(int y, int x, int cnt)
{
	int k, i, j;
	if (cnt >= result)
		return;
	if (x >= 10)
	{
		y = y + 1;
		x = 0;
	}
	if (y >= 10)
	{
		int flag = 1;
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
			{
				if (board[i][j] == 1)
				{
					flag = 0;
					break;
				}
			}
		}
		if (flag == 1)
		{
			result = min(result, cnt);
		}
		return;
	}

	for (k =5; k >0; k--)
	{
		if (paperCount[k] != 0)//k*k사이즈의 색종이가 남는게 있으면 붙일지 말지 고름.
		{
			int flag = test(k, y, x);//flag가 1이면 붙일수 있고, flag가 0이면 붙일수 없음.
			if (flag == 1)//붙일수 있으면 일단 붙여봄.
			{
				change(0, k, y, x);//다 0으로 바꾸어줌.(y, y+k), (x, x+k)의 범위를
				paperCount[k]--;
				find(y, x + k, cnt + 1);//k*k사이즈의 색종이 사용후 다음위치로 넘어감.
				paperCount[k]++;
				change(1, k, y, x);//다 1으로 바꾸어줌.(y, y+k), (x, x+k)의 범위를
			}
		}
	}
	if(board[y][x]==0)//board[y][x]가 0일때만 다음 꺼로 넘어감. 1일 때 붙히지 않고 넘어가면 결국에는 1이 남아있게 되므로.
		find(y, x + 1, cnt);
}

int main(void)
{
	int i, j;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			scanf("%d", &board[i][j]);
		}
	}
	find(0, 0, 0);
	if (result != 1000000)
		printf("%d", result);
	else
		printf("-1");
}
