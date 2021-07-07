#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<int> combination;
vector<vector<int> > board(8, vector<int>(8, 0));
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1} , {0, 1} };
int answer = 0;

void dfs(int y, int x, int n, int m)
{
	board[y][x] = 3;
	for (int i = 0; i < 4; i++)
	{
		int new_y = y + dir[i][0];
		int new_x = x + dir[i][1];
		if (new_y >= n || new_y < 0 || new_x >= m || new_x < 0)
			continue;
		if (board[new_y][new_x] == 0)//벽이 아니면 바이러스는 계속 진행
		{
			dfs(new_y, new_x, n, m);
		}

	}
}

void solution(int n, int m)
{
	vector<vector<int> > temp(n, vector<int> (m, 0));
	int cnt=0;
	int i, j;
	for (i = 0; i < n; i++)//board를 temp에 저장해놓음
	{
		for (j = 0; j < m; j++)
		{
			temp[i][j] = board[i][j];
		}
	}


	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (board[i][j] == 2)//바이러스 지역부터 dfs 돌림
			{
				dfs(i, j, n, m);
			}
		}
	}

	for (i = 0; i < n; i++)//board 복원
	{
		for (j = 0; j < m; j++)
		{
			if (board[i][j] == 0)
				cnt++;
		}
	}

	answer = max(answer, cnt);

	for (i = 0; i < n; i++)//board 복원
	{
		for (j = 0; j < m; j++)
		{
			board[i][j]= temp[i][j];
		}
	}
}

void get_combination(int n, int m)
{
	int i;
	if (combination.size() == 3)//3개 조합을 완성한 경우
	{
		int solution_flag = 1;//3개 조합을 통해 만들어낸 벽이 설치할 수 있는 벽인지의 여부를 체크
		//(바이러스가 있는영역이거나, 벽이 있는 영역이 아닌지)
		set<int>::iterator it;
		for (it = combination.begin(); it != combination.end(); it++)
		{
			int row = (*it) / m;
			int col = (*it) % m;
			if (board[row][col] == 1 || board[row][col] == 2)//바이러스가 있는 영역이거나 벽이 있는 영역인 경우
			{
				solution_flag = 0;//벽을 설치할 수 없는 영역임
				break;
			}
		}
		if (solution_flag == 1)//벽을 설치 할 수 있는 영역인 경우
		{
			//벽을 설치
			for (it = combination.begin(); it != combination.end(); it++)
			{
				int row = (*it) / m;
				int col = (*it) % m;
				board[row][col] = 1;
			}
			solution(n, m);//설치한 벽을 기준으로 시뮬레이션을 돌려 안전영역의 수를 계산
			//벽을 허물음
			for (it = combination.begin(); it != combination.end(); it++)
			{
				int row = (*it) / m;
				int col = (*it) % m;
				board[row][col] = 0;
			}
		}
		return;
	}

	for (i = 0; i < n * m; i++)
	{
		if (combination.find(i) == combination.end())//set안에 없으면 조합안에 넣을 수 있음
		{
			combination.insert(i);
			get_combination(n, m);
			combination.erase(i);
		}
	}
}


int main(void)
{
	int n, m;
	int i, j;
	scanf("%d %d", &n, &m);
	
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &board[i][j]);
		}
	}

	get_combination(n, m);
	printf("%d", answer);
}
