#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#define LEFT 0;
#define RIGHT 1;
#define DOWN 2;
#define UP 3;

using namespace std;

int get_next_direction(int cur_dir, char cmd)
{
	if(cur_dir == 0)
	{
		if(cmd=='L')
		{
			return DOWN;
		}
		else//D
		{
			return UP;
		}
	}
	else if(cur_dir == 1)
	{
		if(cmd=='L')
		{
			return UP;
		}
		else//D
		{
			return DOWN;
		}
	}
	else if(cur_dir == 2)
	{
		if(cmd=='L')
		{
			return RIGHT;
		}
		else//D
		{
			return LEFT;
		}
	}
	else//UP
	{
		if(cmd=='L')
		{
			return LEFT;
		}
		else//D
		{
			return RIGHT;
		}
	}
}

int main(void)
{
	int size, apples;
	int row, col;
	int time=0;
	int cur_dir=RIGHT;
	int dir[4][2]={{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
	int command_cnt;
	int i;
	int heady, headx;
	int taily, tailx;
	heady=headx=0;
	taily=tailx=0;
	scanf("%d %d", &size, &apples);
	vector<vector<int> > board(size, vector<int> (size, 0));
	list<pair<int, char> > command;
	list<pair<int, int> > snake;//뱀의 좌표 저장.
	snake.push_front(make_pair(heady, headx));
	for(i=0; i < apples; i++)
	{
		scanf("%d %d", &row, &col);
		board[row-1][col-1]=1;
	}
	scanf("%d", &command_cnt);
	for(i=0; i< command_cnt; i++)
	{
		pair<int, char> temp;
		scanf("%d %c", &temp.first, &temp.second);
		command.push_back(temp);
	}
	while(1)
	{
		time++;
		heady=heady+dir[cur_dir][0];
		headx=headx+dir[cur_dir][1];
		if(heady>=size || headx>=size || heady<0 || headx<0)//뱀의 머리가 맵밖으로 벗어난 경우
		{
			break;
		}
		int finish_flag=0;
		if(board[heady][headx]==1)//사과를 먹은 경우
		{
			board[heady][headx]=0;
			snake.push_front(make_pair(heady, headx));
		}
		else
		{
			snake.push_front(make_pair(heady, headx));
			list<pair<int, int> >::iterator it=snake.begin();

			it++;
			for(;it!=snake.end(); it++)
			{
				if(heady==(*it).first && headx==(*it).second)
				{
					finish_flag=1;
					break;
				}
			}
			snake.pop_back();
		}


		if(finish_flag)
			break;

		if(!command.empty() && time==(*command.begin()).first)
		{
			cur_dir=get_next_direction(cur_dir, (*command.begin()).second);
			command.pop_front();
		}
	}
	printf("%d", time);
}
