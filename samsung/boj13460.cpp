#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int redi, redj;
int bluei, bluej;
int hole;
int dfs(int count, vector<vector<char> > &board)
{
	int i, j;
	int result=100;
	int flag = 2;
	if (count > 10)
		return result;
	int lastredi=redi;
	int lastredj=redj;
	int lastbluei=bluei;
	int lastbluej=bluej;
	///////위쪽
	redi = lastredi;
	redj = lastredj;
	bluei = lastbluei;
	bluej = lastbluej;
	flag = 2;
	if (redj == bluej)
	{
		if (redi < bluei)
		{
			for (i = redi; board[i][redj] != '#'; i--)
			{
				redi = i;
				if (board[redi][redj] == 'O')
					flag = 1;
			}
			for (i = bluei; board[i][bluej] != '#' && i > redi; i--)
			{
				bluei = i;
				if (board[bluei][bluej] == 'O')
					flag = 0;
			}
			if (board[i][bluej] == 'O')
				flag = 0;
		}
		else
		{
			for (i = bluei; board[i][bluej] != '#'; i--)
			{
				bluei = i;
				if (board[bluei][bluej] == 'O')
					flag = 0;
			}
			for (i = redi; board[i][redj] != '#' && bluei < i; i--)
			{
				redi = i;
				if (board[redi][redj] == 'O' && flag != 0)
					flag = 1;
			}
		}
	}
	else
	{
		for (i = redi; board[i][redj] != '#'; i--)
		{
			redi = i;
			if (board[redi][redj] == 'O')
				flag = 1;
		}
		for (i = bluei; board[i][bluej] != '#'; i--)
		{
			bluei = i;
			if (board[bluei][bluej] == 'O')
				flag = 0;
		}

	}
	if (flag == 0)
		;
	else if (flag == 1)
		return count;
	else
		result = min(result, dfs(count + 1, board));
	////////오른쪽
	redi = lastredi;
	redj = lastredj;
	bluei = lastbluei;
	bluej = lastbluej;
	flag = 2;
	if (redi == bluei)
	{
		if (redj > bluej)
		{
			for (j = redj; board[redi][j] != '#'; j++)
			{
				redj = j;
				if (board[redi][redj] == 'O')
					flag = 1;
			}
			for (j = bluej; board[bluei][j] != '#' && j < redj; j++)
			{
				bluej = j;
				if (board[bluei][bluej] == 'O')
					flag = 0;
			}
			if (board[bluei][j] == 'O')
				flag = 0;
		}
		else
		{
			for (j = bluej; board[bluei][j] != '#'; j++)
			{
				bluej = j;
				if (board[bluei][bluej] == 'O')
					flag = 0;
			}
			for (j = redj; board[redi][j] != '#' && bluej > j; j++)
			{
				redj = j;
				if (board[redi][redj] == 'O' && flag != 0)
					flag = 1;
			}
		}
	}
	else
	{
		for (j = redj; board[redi][j] != '#'; j++)
		{
			redj = j;
			if (board[redi][redj] == 'O')
				flag = 1;
		}
		for (j = bluej; board[bluei][j] != '#'; j++)
		{
			bluej = j;
			if (board[bluei][bluej] == 'O')
				flag = 0;
		}

	}
	if (flag == 0)
		;
	else if (flag == 1)
		return count;
	else
		result = min(result, dfs(count + 1, board));
	/////////왼쪽
	redi = lastredi;
	redj = lastredj;
	bluei = lastbluei;
	bluej = lastbluej;
	flag = 2;
	if (redi == bluei)
	{
		if (redj < bluej)
		{
			for (j = redj; board[redi][j]!='#'; j--)
			{
				redj = j;
				if (board[redi][redj] == 'O')
					flag = 1;
			}
			for (j = bluej; board[bluei][j] != '#' && j > redj; j--)
			{
				bluej = j;
				if (board[bluei][bluej] == 'O')
					flag = 0;
			}
			if (board[bluei][j] == 'O')
				flag = 0;
		}
		else
		{
			for (j = bluej; board[bluei][j] != '#'; j--)
			{
				bluej = j;
				if (board[bluei][bluej] == 'O')
					flag = 0;
			}
			for (j = redj; board[redi][j] != '#' && bluej < j; j--)
			{
				redj = j;
				if (board[redi][redj] == 'O' && flag != 0)
					flag = 1;
			}
		}
	}
	else
	{
		for (j = redj; board[redi][j] != '#'; j--)
		{
			redj = j;
			if (board[redi][redj] == 'O')
				flag = 1;
		}
		for (j = bluej; board[bluei][j] != '#'; j--)
		{
			bluej = j;
			if (board[bluei][bluej] == 'O')
				flag = 0;
		}
	}
	if (flag == 0)
		;
	else if (flag == 1)
		return count;
	else
		result = min(result, dfs(count + 1, board));
	
	///////아래
	redi = lastredi;
	redj = lastredj;
	bluei = lastbluei;
	bluej = lastbluej;
	flag = 2;
	if (redj == bluej)
	{
		if (redi > bluei)
		{
			for (i = redi; board[i][redj] != '#'; i++)
			{
				redi = i;
				if (board[redi][redj] == 'O')
					flag = 1;
			}
			for (i = bluei; board[i][bluej] != '#' && i < redi; i++)
			{
				bluei = i;
				if (board[bluei][bluej] == 'O')
					flag = 0;
			}
			if (board[i][bluej] == 'O')
				flag = 0;
		}
		else
		{
			for (i = bluei; board[i][bluej] != '#'; i++)
			{
				bluei = i;
				if (board[bluei][bluej] == 'O')
					flag = 0;
			}
			for (i = redi; board[i][redj] != '#' && bluei > i; i++)
			{
				redi = i;
				if (board[redi][redj] == 'O' && flag != 0)
					flag = 1;
			}
		}
	}
	else
	{
		for (i = redi; board[i][redj] != '#'; i++)
		{
			redi = i;
			if (board[redi][redj] == 'O')
				flag = 1;
		}
		for (i = bluei; board[i][bluej] != '#';i++)
		{
			bluei = i;
			if (board[bluei][bluej] == 'O')
				flag = 0;
		}

	}
	if (flag == 0)
		;
	else if (flag == 1)
		return count;
	else
		result = min(result, dfs(count + 1, board));
	
	return result;
}


int main(void)
{

	scanf("%d %d", &n, &m);
	vector<vector<char> > board(n, vector<char>(m, 0));
	char temp;
	for (int i = 0; i < n; i++)
	{
		scanf("%c", &temp);//to get space
		for (int j = 0; j < m; j++)
		{
			scanf("%c", &board[i][j]);
			if (board[i][j] == 'R')
			{
				redi = i;
				redj = j;
				board[i][j] == '.';
			}
			else if (board[i][j] == 'B')
			{
				bluei = i;
				bluej = j;
				board[i][j] == '.';
			}
		}
	}
	int result = dfs(1, board);
	if (result == 100)
		result = -1;
	printf("%d", result);
}
