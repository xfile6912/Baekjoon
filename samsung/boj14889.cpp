#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int team[2];
vector<int> teama;
vector<int> teamb;
int difference = 987654321;
void dfs(int cnt, vector<vector<int> > &board)
{
	if (teama.size()==n/2 && teamb.size()==n/2)
	{
		int teama_level = 0;
		int teamb_level = 0;
		for (int i = 0; i < teama.size(); i++)
		{
			for (int j = i + 1; j < teama.size(); j++)
			{
				teama_level += (board[teama[i]][teama[j]] + board[teama[j]][teama[i]]);
				teamb_level += (board[teamb[i]][teamb[j]] + board[teamb[j]][teamb[i]]);
			}
		}
		difference = min(difference, abs(teama_level - teamb_level));

		return;
	}

	if (team[0] > 0)
	{
		team[0]--;
		teama.push_back(cnt);
		dfs(cnt + 1, board);
		teama.pop_back();
		team[0]++;
	}
	if (team[1] > 0)
	{
		team[1]--;
		teamb.push_back(cnt);
		dfs(cnt + 1, board);
		teamb.pop_back();
		team[1]++;
	}
}

int main(void)
{
	scanf("%d", &n);
	vector<vector<int> > board(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &board[i][j]);
		}
	}
	team[0] = n / 2;
	team[1] = n / 2;
	dfs(0, board);
	printf("%d", difference);
}
