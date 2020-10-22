#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int main(void)
{
	int testCase;
	int receptNum, repairNum, clientNum;//reception, repair 창구의 개수, 고객의 수
	int receptGet, repairGet;//지갑을 놓고간 고객이 이용한 창구
	int i, j;
	int time;
	scanf("%d", &testCase);
	for(j=1; j<=testCase; j++)
	{
		scanf("%d %d %d %d %d", &receptNum, &repairNum, &clientNum,&receptGet, &repairGet);
		vector<int> receptTime(receptNum, 0);//i번째 접수창구 시간
		vector<int> repairTime(repairNum, 0);//j번째 정비창구 시간
		vector<int> visitTime(clientNum, 0);//방문 시간
		vector<vector<int> > reception(receptNum, vector<int> (2,-1));//실제 창구 [0]에는 고객의 번호, [1]에는 고객의 남은 시간
		vector<vector<int> > repair(repairNum, vector<int>(2, -1));//실제 창구[0]에는 고객의 번호, [1]에는 고객의 남은 시간
		vector<vector<int> > client(clientNum, vector<int>(2, -1));//[0]은 고객이 이용한 접수창구, [1]은 고객이 이용한 정비창구
		queue<int> receptQueue;
		queue<int> repairQueue;
		for (i = 0; i < receptNum; i++)
			scanf("%d", &receptTime[i]);
		for (i = 0; i < repairNum; i++)
			scanf("%d", &repairTime[i]);
		for (i = 0; i < clientNum; i++)
			scanf("%d", &visitTime[i]);
		time = visitTime[0];
		int cnt = 0;//다 끝났는지 알아보는 flag;
		while (1)
		{
			for (i = 0; i < clientNum; i++)
			{
				if (visitTime[i] == time)
				{
					receptQueue.push(i);
				}
			}
			for (i = 0; i < repairNum; i++)
			{
				if (repair[i][0] == -1 && !repairQueue.empty())//해당 정비 창구가 비어 있으고 대기하는 손님이 있으면
				{
					cnt++;
					repair[i][0] = repairQueue.front();
					client[repair[i][0]][1] = i;
					repair[i][1] = repairTime[i];
					repairQueue.pop();
				}
				if (repair[i][0] != -1)//정비창구에 손님이 있으면
				{
					repair[i][1]--;//시간 1초감소해줌. time이 증가되기 때문에
					if (repair[i][1] == 0)//시간이 다 끝났다면//해당 정비 창구를 비워줌.
					{
						repair[i][0] = -1;
						repair[i][1] = -1;
					}
				}
			}

			if (cnt == clientNum)//정비창구를 지나간 사람 수가 client수와 같다면. 모두 다 정비창구 까지 간거임
			{
				break;
			}


			for (i = 0; i < receptNum; i++)
			{
				if (reception[i][0] == -1 && !receptQueue.empty())//해당 접수 창구가 비어 있으고 대기하는 손님이 있으면
				{
					reception[i][0] = receptQueue.front();
					client[reception[i][0]][0] = i;
					reception[i][1] = receptTime[i];
					receptQueue.pop();
				}
				if (reception[i][0] != -1)//접수창구에 손님이 있으면
				{
					reception[i][1]--;//시간 1초감소해줌. time이 증가되기 때문에
					if (reception[i][1] == 0)//시간이 다 끝났다면//해당 접수창구를 비워주고 정비창구 큐에 넣어줌.
					{
						repairQueue.push(reception[i][0]);
						reception[i][0] = -1;
						reception[i][1] = -1;
					}
				}
			}


			time++;
		}
		int sum = 0; //고객번호의 합.
		for (i = 0; i < clientNum; i++)
		{
			if (client[i][0] == receptGet-1 && client[i][1] == repairGet-1)
				sum += i + 1;
		}
		if (sum == 0)
			sum = -1;
		printf("#%d %d\n", j, sum);
	}
	return 0;
}

