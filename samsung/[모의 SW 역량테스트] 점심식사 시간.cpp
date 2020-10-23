#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


pair<int, int> stair[2];//first는 y좌표, second는 x좌표
int cost[2];//stair의 cost;
vector<pair<int, int> > person;//person[i].first는 y좌표 second는 x좌표
int personNum;//사람의수
vector<int> combination;//사람이 어떤계단으로 들어갈지 조합 저장
int result = 987654321;
int solution() {
	int i, j;
	int time = 0;
	int stairPick;
	int absy, absx;
	int distance;
	int waiting[2];//대기하는 사람 수;
	vector<int> executing[2];////stair 이용하고있는 큐;
	waiting[0] = 0;
	waiting[1] = 0;
	int cnt=0;
	while (1)
	{
		if (cnt == personNum)
		{
			return time;
		}
		/// <summary>
		// 계단0
		/// </summary>
		while (executing[0].size() != 3 && waiting[0]!=0)//기다리는 사람이 있고, executing이 비어있으면
		{
			executing[0].push_back(cost[0]);
			waiting[0]--;
		}
		for (i = 0; i < executing[0].size(); i++)
		{
			executing[0][i]--;
			if (executing[0][i] == 0)//계단에 있는사람이 다 내려갔을 때
			{
				executing[0].erase(executing[0].begin() + i);
				i--;
				cnt++;
			}
		}
		/// <summary>
		/// 계단1
		/// </summary>
		while (executing[1].size() != 3 && waiting[1] != 0)//기다리는 사람이 있고, executing이 비어있으면
		{
			executing[1].push_back(cost[1]);
			waiting[1]--;
		}
		for (i = 0; i < executing[1].size(); i++)
		{
			executing[1][i]--;
			if (executing[1][i] == 0)
			{
				executing[1].erase(executing[1].begin() + i);
				i--;
				cnt++;
			}
		}
		for (i = 0; i < personNum; i++)
		{
			stairPick = combination[i];//i번째 사람이 고른 계단
			absy=abs(person[i].first-stair[stairPick].first);
			absx= abs(person[i].second - stair[stairPick].second);
			distance = absy + absx;//걸리는 시간.
			if (distance - time == 0)//i번째 사람이 계단입구에 도착한 시간->time
			{
				if (stairPick == 0)//각각 waiting queue에 넣어줌.
					waiting[0]++;
				if (stairPick == 1)
					waiting[1]++;
			}
		}
		time++;
	}
}

void makeCombination()
{
	if (combination.size() == personNum)
	{
		result = min(result, solution());
		return;

	}

	combination.push_back(0);
	makeCombination();//i번째 사람이 0번방 들어갔을때
	combination.pop_back();

	combination.push_back(1);//i번째 사람이 1번방 들어갔을때;
	makeCombination();
	combination.pop_back();
}

int main(void)
{
	int testCase;
	int n;
	int i, j, k;
	scanf("%d", &testCase);
	for (k = 1; k <= testCase; k++)
	{
		result = 987654321;
		personNum = 0;
		person.clear();
		combination.clear();
		scanf("%d", &n);
		vector<vector<int> > map(n, vector<int>(n, 0));//방 생성

		int temp = 0;//계단정보를 넣기위한 cnt변수
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				scanf("%d", &map[i][j]);//방 정보 입력받음.
				if (map[i][j] == 1)
					person.push_back(make_pair(i, j));
				if (map[i][j] > 1)
				{
					stair[temp].first = i;
					stair[temp].second = j;
					cost[temp] = map[i][j];
					temp++;
				}
			}
		}
		personNum = person.size();
		makeCombination();
		printf("#%d %d\n", k, result);
	}
}

