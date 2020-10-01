#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int result = 0;
int n;
vector<int> order;//타자들의 순서.
vector<int> visited(9, 0);
//0은 1번타자, 1은 2번타자 이런식으로 증가.
void getResult(vector<vector<int> > &info)
{
	int i,j;
	int outCount=0;
	int score = 0;//score
	int currentHitter;//현재타자.
	int lastHitter = 8;//이닝종료전 마지막 히터//1이닝에서는 9번타자가 마지막 타자라고 가정.
	int base[3];///0은 1루, 1은 2루, 2는 3루, 3은 홈.
	for (i = 0; i < n; i++)
	{
		outCount = 0;//이닝당 아웃카운트는 0에서 시작.
		base[2] = 0;
		base[1] = 0;
		base[0] = 0;//이닝 시작에는 베이스에 아무도 없음.
		while (outCount != 3)
		{
			currentHitter = lastHitter + 1;//현재 타자는 이전타자 +1임.
			if (currentHitter == 9)//타선이 한바퀴 돌아 1번타자로 타자가 바뀌어야함.
				currentHitter = 0;
			if (info[i][order[currentHitter]] == 0)//현재이닝의 현재타자가 아웃이라면
			{
				outCount++;
			}
			else if (info[i][order[currentHitter]] == 1)//안타인 경우
			{
				if (base[2] == 1)
					score += 1;
				base[2] = base[1];
				base[1] = base[0];
				base[0] = 1;
			}
			else if (info[i][order[currentHitter]] == 2)//2루타인 경우
			{
				if (base[2] == 1)//3루에 주자가 있었다면 점수 1점 추가
					score += 1;
				if (base[1] == 1)//2루에 주자가 있었다면 점수 1점 추가.
					score += 1;
				base[2] = base[0];//1루 주자가 3루로 이동
				base[1] = 1;//2루에 주자한명생김
				base[0] = 0;//1루에는 주자 없음
			}
			else if (info[i][order[currentHitter]] == 3)//3루타인 경우
			{
				if (base[2] == 1)//3루에 주자가 있었다면 점수 1점 추가
					score += 1;
				if (base[1] == 1)//2루에 주자가 있었다면 점수 1점 추가.
					score += 1;
				if (base[0] == 1)//1루에 주자가 있었다면 점수 1점 추가.
					score += 1;
				base[2] = 1;//3루에 주자 한명 생김.
				base[1] = 0;
				base[0] = 0;
			}
			else if (info[i][order[currentHitter]] == 4)//홈런인 경우.
			{
				score += 1;//hitter가 홈에 들어옴.
				if (base[2] == 1)//3루에 주자가 있었다면 점수 1점 추가
					score += 1;
				if (base[1] == 1)//2루에 주자가 있었다면 점수 1점 추가.
					score += 1;
				if (base[0] == 1)//1루에 주자가 있었다면 점수 1점 추가.
					score += 1;
				base[2] = 0;//베이스에 주자없음.
				base[1] = 0;//베이스에 주자없음.
				base[0] = 0;//베이스에 주자없음.
			}
			lastHitter = currentHitter;//현재타자가 이제 이전 타자가 됨.
		}
	}
	result = max(result, score);
}
void solution(vector<vector<int> > &info)//타자 순서의 조합을 만들고 다 만들어지면 결과찾음.
{
	int i;
	if (order.size() == 9)//조합이 완성되면 그 조합으로 나오는 결과 찾음.
	{
		getResult(info);
		return;
	}

	if (order.size() == 3)//4번타자는 1번타자임.
		order.push_back(0);
	for (i = 1; i < 9; i++)
	{
		if (visited[i] == 0)
		{
			visited[i] = 1;
			order.push_back(i);
			solution(info);
			order.pop_back();
			visited[i] = 0;
		}
	}
	if (order.size() == 4)//4번타자는 1번타자.
		order.pop_back();
}

int main(void)
{

	scanf("%d", &n);
	vector<vector<int> > info(n, vector<int>(9, 0));
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 9; j++)
		{
			scanf("%d", &info[i][j]);//이닝당 정보.
		}
	}
	solution(info);
	printf("%d", result);
}
