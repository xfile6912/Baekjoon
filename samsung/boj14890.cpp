#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int num, length;

int solve(vector<vector<int> > &map)//행의 길 개수 구함
{
	int count = 0;
	for (int i = 0; i < num; i++)
	{
		int road_flag = 1;//길을 만들수 있는지 없는지에 대한 flag;
		vector<int> slope(num, 0);//경사로가 있는지 없는지를 나타냄
		for (int j = 0; j < num - 1; j++)
		{
			if (map[i][j] != map[i][j + 1])//높이가 서로 다른 경우
			{
				if (abs(map[i][j] - map[i][j + 1]) != 1)//높이 차이가 1이아니면 road_flag=0으로 바꾸어줌
				{
					road_flag = 0;
					break;
				}
				else if (map[i][j] > map[i][j + 1])//오른쪽으로 경사를 만들어야하는 경우
				{
					if (j + length >= num)//범위를 넘어가는경우
					{
						road_flag = 0;
						break;
					}
					for (int k = 1; k <= length; k++)
					{
						if (map[i][j + 1] != map[i][j + k] || slope[j + k] == 1)//경사로를 만들 곳이 높이가 같지 않거나, 이미 경사로가 설치되어 있으면
						{
							road_flag = 0;
							break;
						}
						slope[j + k] = 1;//경사로 설치
					}
					if (road_flag == 0)
						break;
				}
				else//왼쪽으로 경사를 만들어야하는경우
				{
					if (j + 1 - length < 0)//범위를 넘어가는경우
					{
						road_flag = 0;
						break;
					}
					for (int k = 0; k < length; k++)
					{
						if (map[i][j] != map[i][j - k] || slope[j - k] == 1)//경사로를 만들 곳이 높이가 같지 않거나, 이미 경사로가 설치되어 있으면
						{
							road_flag = 0;
							break;
						}
						slope[j - k] = 1;//경사로 설치
					}
					if (road_flag == 0)
						break;
				}
			}
		}
		if (road_flag == 1)
			count++;
	}
	return count;
}

void rotate(vector<vector<int> >& map)
{
	vector<vector<int> > temp(num, vector<int> (num, 0));
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
			temp[i][j] = map[i][j];
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
			map[i][j] = temp[j][i];
	}
}

int main(void)
{
;
	int count=0;
	scanf("%d %d", &num, &length);
	vector<vector<int> > map(num, vector<int>(num, 0));
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			scanf("%d", &map[i][j]);

	count += solve(map);
	rotate(map);
	count += solve(map);
	printf("%d", count);
}
