#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;


long long int area(int start, int end, vector<long long>& arr)
{
	int half;
	half = (start + end) / 2;
	long long temp;
	long long max;
	long long temparea;
	int i, j;
	long long minheight;

	if (start == end)
		return arr[start];


	max = area(start, half, arr);//왼쪽 구간
	temp = area(half + 1, end, arr);//오른쪽 구간
	if (max < temp)
		max = temp;

////////////////////////////////////중앙구간
	i = half;
	j = half + 1;
	if (arr[i] > arr[j])
		minheight = arr[j];
	else
		minheight = arr[i];
	temparea = minheight * 2;//직사각형의 넓이는 더 작은 값을 이용해서 구해야함.

	while (1)
	{
		if (i == start && j == end)
			break;

		if (i == start)
		{
			j++;
		}
		else if (j == end)
		{
			i--;
		}
		else if (i>start && arr[i - 1] >= arr[j + 1])//왼쪽과 오른쪽중에 더 높은 곳을 선택.
		{
			i--;
		}
		else if(j<end && arr[i-1]<arr[j+1])
		{
			j++;
		}
		if (arr[i] < minheight)//선택된 구간만큼에서 가장 작은 높이를 이용해 넓이를 계산해야 직사각형 넓이를 구할수 있다.
			minheight = arr[i];
		if (arr[j] < minheight)
			minheight = arr[j];
		if (temparea < minheight * (j - i + 1))
			temparea = minheight * (j - i + 1);
	}
	if (temparea > max)
		return temparea;
	return max;


}

int main(void)
{
	int n;
	int i;
	long long result;
	while(1)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		vector<long long> arr(n, 0);
		for (i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		result = area(0, n-1, arr);
		cout << result << endl;
	}
}	


