#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
using namespace std;

//베시가 쉬는 구간에 먼저 도착해서 존이 그 구역에 도착할 때까지 쉬면 된다.
//단 가장 많은 이익을 올려야하므로 이익이 가장 큰 곳에 먼저 도착해서 쉬다가 존이오면
//다음 이익이 큰곳으로 옮겨야 한다.


bool compare(vector<int> x, vector<int> y)
{
	return x[1] > y[1];
}

int main(void)
{
	int length, n, rf, rb;
	long long result = 0;//베시가 얻은 총 이익
	long long timeb;
	long long timej;
	scanf("%d %d %d %d", &length, &n, &rf, &rb);
	vector<vector<int> > reststop(n, vector<int>(2, 0));//[0]은 stop의 위치,[1]은 stop에서의 이익 ;
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &reststop[i][0], &reststop[i][1]);
	}
	sort(reststop.begin(), reststop.end(), compare);//쉬는 곳에서의 이익이 큰순으로 정렬
	int laststop=0;//이전에 베시가 쉬었던 장소//초기화는 0으로 해준다. 처음에는 출발점에서 같이 출발하므로
	for (i = 0; i < n; i++)
	{
		if (reststop[i][0] > laststop)//이전에 쉬었던 위치보다 뒤에 있는 위치여야 함
		{//이전 stop에서 같이 출발하므로 현재 수리 stop에서 이전 stop의 거리를 빼준다.
			timeb = (reststop[i][0]-laststop) * (long long)rb;//이전 stop부터 현재 쉴 stop까지 베시가 오기까지 걸리는 시간 
			timej = (reststop[i][0]-laststop) * (long long)rf;// 이전 stop부터 현재 쉴 stop까지 존이 오기까지 걸리는 시간
			result += (timej - timeb) * reststop[i][1];//존이 도착 할때까지 쉴수 있다.
			laststop = reststop[i][0];
		}
	}
	printf("%lld", result);
}
