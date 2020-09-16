#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, d;
vector<int> arrow;
int result=0;

int cal(vector<vector<int> > board)
{
	int i, j, k;
	int t;
	int cnt = 0;
	for(t=0; t<n; t++)
	{
		vector<pair<int, int> > st;
		for (k = 0; k < 3; k++)
		{
			int mindistance = d;
			int mini = -1, minj = -1;
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					if (board[i][j] != 1)
						continue;
					int distance = (n - i) + abs(arrow[k] - j);
					if (distance < mindistance)
					{
						mindistance = distance;
						mini = i;
						minj = j;
					}
					else if (distance == mindistance && mini == -1 && minj == -1)
					{
						mindistance = distance;
						mini = i;
						minj = j;
					}
					else if (distance == mindistance)
					{
						if (j < minj)
						{
							mini = i;
							minj = j;
						}
					}
				}
			}
			if(mini!=-1 && minj!=-1)
				st.push_back(make_pair(mini, minj));
		}
		for (k = 0; k <st.size(); k++)
		{
			if (board[st[k].first][st[k].second] != 0)
			{
				board[st[k].first][st[k].second] = 0;
				cnt++;
			}
		}
		for (k = 0; k < st.size(); k++)
		{
			st.pop_back();
		}
		for (i = n-1; i > 0; i--)
		{
			for (j = 0; j < m; j++)
			{
				board[i][j] = board[i - 1][j];
			}
		}
		for (j = 0; j < m; j++)
		{
			board[0][j] = 0;
		}
	}
	return cnt;
}

void find(int start, int count, vector<vector<int> >& board)
{
	if (count == 0)
	{
		for (int j = 0; j < m; j++)
		{
			board[n][j] = 0;//궁수 위치 초기화
		}
		for (int j = 0; j < 3; j++)
		{
			board[n][arrow[j]] = 10;//궁수 설정.
		}
		result = max(result, cal(board));
		return;
	}
	for (int j = start; j < m - count+1; j++)
	{
		arrow.push_back(j);
		find(j + 1, count - 1, board);
		arrow.pop_back();
	}
	printf("");
}

int main(void)
{
	scanf("%d %d %d", &n, &m, &d);
	vector<vector<int> > board(n + 1, vector<int>(m, 0));
	int i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			scanf("%d", &board[i][j]);
	}
	find(0, 3, board);
	printf("%d", result);
}
