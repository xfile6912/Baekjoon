#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct germGroup {
	int y;
	int x;
	int numOfGerm;//미생물 수
	int move;//이동방향
};//미생물 군집 정보


int main(void)
{
	int testCase;
	int cellNum, time, groupNum;//셀의개수, 격리시간, 미생물 군집의 개수
	scanf("%d", &testCase);
	int i, j, k, l;
	for (k = 1; k <= testCase; k++)
	{
		vector<germGroup> germs;
		scanf("%d %d %d", &cellNum, &time, &groupNum);
		for (i = 0; i < groupNum; i++)
		{
			int y, x, numOfGerm, move;
			germGroup temp;
			scanf("%d %d %d %d", &y, &x, &numOfGerm, &move);//정보 입력받음.
			temp.y= y;//cell에 정보담음
			temp.x = x;//cell에 정보담음
			temp.numOfGerm = numOfGerm;//cell에 정보담음
			temp.move = move;//cell에 정보 담음.
			germs.push_back(temp);
		}
		for (l = 0; l < time; l++)
		{
			for (i = 0; i < germs.size(); i++)
			{
				if (germs[i].move == 1)//위로움직이는경우
				{
					germs[i].y-=1;
					if (germs[i].y == 0)//약품처리한 곳에 도달
					{
						germs[i].numOfGerm /= 2;//미생물 수가 1/2로 감소함.
						germs[i].move = 2;//방향이 반대로 바뀜
					}
				}
				else if (germs[i].move == 2)//아래로 움직이는경우
				{
					germs[i].y+= 1;
					if (germs[i].y == cellNum-1)//약품처리한 곳에 도달
					{
						germs[i].numOfGerm /= 2;//미생물 수가 1/2로 감소함.
						germs[i].move = 1;//방향이 반대로 바뀜
					}
				}
				else if (germs[i].move == 3)//좌로 움직이는경우
				{
					germs[i].x -= 1;
					if (germs[i].x == 0)//약품처리한 곳에 도달
					{
						germs[i].numOfGerm /= 2;//미생물 수가 1/2로 감소함.
						germs[i].move = 4;//방향이 반대로 바뀜
					}
				}
				else if (germs[i].move == 4)//우로 움직이는경우
				{
					germs[i].x += 1;
					if (germs[i].x == cellNum-1)//약품처리한 곳에 도달
					{
						germs[i].numOfGerm /= 2;//미생물 수가 1/2로 감소함.
						germs[i].move = 3;//방향이 반대로 바뀜
					}
				}
				if (germs[i].numOfGerm == 0)
				{
					germs.erase(germs.begin() + i);
					i--;
				}
			}
			for (i = 0; i < germs.size(); i++)
			{
				int y = germs[i].y;
				int x = germs[i].x;
				int maxNumber = germs[i].numOfGerm;//y좌표와 x좌표가 같은 군집중 최대 군집 수 저장.
				int germSum=germs[i].numOfGerm;//y좌표와 x좌표 같은 군집의 모든 미생물 수의 합.
				int move = germs[i].move;//최종 이동방향.
				for (j = i+1; j < germs.size(); j++)//germs군집중에 좌표가 같은 군집을 찾음.
				{
					if (germs[j].y == y && germs[j].x == x)//좌표가 같은 군집을 찾았을 때
					{
						if (maxNumber < germs[j].numOfGerm)
						{
							maxNumber = germs[j].numOfGerm;
							move = germs[j].move;//이동방향은 군집의 미생물이 가장 많은 군집의 방향으로 바뀌게 됨.
						}
						germSum += germs[j].numOfGerm;//미생물 수 통합해줌.
						germs.erase(germs.begin() + j);//이 군집은 지워줌.
						j--;
					}
				}
				germs[i].numOfGerm = germSum;//미생물 수 통합해준거 반영.
				germs[i].move = move;
			}
		}
		int total=0;
		for (i = 0; i < germs.size(); i++)
		{
			total += germs[i].numOfGerm;
		}
		printf("#%d %d\n", k, total);
	}
}

