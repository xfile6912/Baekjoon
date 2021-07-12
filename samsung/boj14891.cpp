#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;
char gear[4][9];//각 톱니바퀴 나타냄
int gear_idx[4] = { 0, 0, 0, 0 };//12시방향을 나타내는 index

void left(int gear_num, int dir)//오른쪽 톱니바퀴
{
	if (gear_num == 0)
		return;
	
	//두 톱니바퀴가 서로 마주보는 극이 같은경우 움직이지 않음
	if (gear[gear_num][(gear_idx[gear_num] + 6) % 8] == gear[gear_num - 1][(gear_idx[gear_num - 1] + 2) % 8])
	{
		return;
	}
	
	left(gear_num - 1, dir * (-1));

	gear_idx[gear_num - 1] = (gear_idx[gear_num - 1] + dir) % 8;
	if (gear_idx[gear_num - 1] < 0)
		gear_idx[gear_num - 1] = 7;


	
}
void right(int gear_num, int dir)//오른쪽 톱니바퀴
{
	if (gear_num == 3)
		return;

	//두 톱니바퀴가 서로 마주보는 극이 같은경우 움직이지 않음
	if (gear[gear_num][(gear_idx[gear_num] + 2) % 8] == gear[gear_num + 1][(gear_idx[gear_num + 1] + 6) % 8])
	{
		return;
	}

	right(gear_num + 1, dir * (-1));

	gear_idx[gear_num + 1] = (gear_idx[gear_num + 1] + dir) % 8;
	if (gear_idx[gear_num + 1] < 0)
		gear_idx[gear_num + 1] = 7;



}

int main(void)
{

	int k;
	int score = 0;
	scanf("%s", gear[0]);
	scanf("%s", gear[1]);
	scanf("%s", gear[2]);
	scanf("%s", gear[3]);

	scanf("%d", &k);


	for (int i = 0; i < k; i++)
	{
		int gear_num, dir;
		scanf("%d %d", &gear_num, &dir);
		gear_num--;
		left(gear_num, dir);
		right(gear_num, dir);

		gear_idx[gear_num] = (gear_idx[gear_num] - dir) % 8;//선택한 톱니바퀴
		if (gear_idx[gear_num] < 0)
			gear_idx[gear_num] = 7;
	}

	int mult = 1;
	for (int i = 0; i < 4; i++)
	{
		if (gear[i][gear_idx[i]] == '1')
		{
			score += mult;
		}
		mult *= 2;
	}
	printf("%d", score);
}
