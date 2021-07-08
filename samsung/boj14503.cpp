#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
#define WALL 1
#define CLEANED 2

using namespace std;

int dir[4][2] = { {-1,0}, {0, 1}, {1, 0}, {0, -1} };
int cleaned_cnt = 0;//로봇 청소기가 청소한 칸의 개수
int n, m;


void clean(int r, int c, int cur_dir, vector<vector<int> > &board)//로봇청소기의 현재 좌표 및 방향
{
	while (1)
	{
		//1번//
		if (board[r][c] != CLEANED)
		{
			cleaned_cnt++;
			board[r][c] = CLEANED;//현재 위치를 청소
		}
		//1번//
		//2번//
		int i;
		for(i=0; i<4; i++)
		{
			cur_dir--;
			if (cur_dir < NORTH)//북쪽보다 작아지는 경우 서쪽
				cur_dir = WEST;

			int next_r = r + dir[cur_dir][0];
			int next_c = c + dir[cur_dir][1];
			if (next_r >= n || next_c >= m || next_r < 0 || next_c < 0 || board[next_r][next_c] == WALL || board[next_r][next_c] == CLEANED)
			{//현재 바라보는 공간에 청소할 공간이 없다면
				continue;
			}
			else//청소할 공간이 있다면
			{
				r = next_r;
				c = next_c;
				break;
			}
		}
		if (i == 4)//네방향 모두 청소가 이미 되어있는 경우가나 벽인 경우
		{
			int next_r = r+dir[(cur_dir + 2) % 4][0];
			int next_c= c+dir[(cur_dir + 2) % 4][1];
			
			//후진도 못하는 경우 작동을 멈춤
			if (next_r >= n || next_c >= m || next_r < 0 || next_c < 0 || board[next_r][next_c] == WALL)
				break;
			else//후진을 할 수 있는 경우 후진
			{
				r = next_r;
				c = next_c;
			}
		}
	}
}

int main(void)
{

	int cur_dir;//로봇 청소기가 바라보는 방향
	int r, c;//로봇 청소기의 좌표

	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &r, &c, &cur_dir);
	
	vector<vector<int> > board(n, vector<int>(m, 0));//board

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &board[i][j]);
		}
	}
	clean(r, c, cur_dir, board);
	printf("%d", cleaned_cnt);
}
