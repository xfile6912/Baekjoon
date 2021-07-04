#include <stdio.h>
#include <vector>
#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4

using namespace std;

int dir[5][2]={{0,0}, {0, 1},{0, -1},{-1, 0},{1, 0}};
int dice[7]={0};
int main(void)
{
    int n, m;//지도의 크기
    int r, c;//주사위의 행과 열
    int k;//명령의 개수
    int bottom=6;//지도와 닿아있는 밑면의 주사위 인덱스
    int east=3;//지도의 동쪽방면을 가리키는 주사위 인덱스
    int south=2;//지도의 남쪽방면을 가리키는 주사위 인덱스

    scanf("%d %d %d %d %d", &n, &m, &r, &c, &k);
    vector<vector<int> > map(n, vector<int> (m, 0));
    vector<int> order(k, -1);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    for(int i=0; i<k; i++)
    {
        scanf("%d", &order[i]);
    }
    for(int i=0; i<k; i++)
    {
        //order수행시 다음 좌표
        int next_r=r+dir[order[i]][0];
        int next_c=c+dir[order[i]][1];
        //order수행시 다음 주사위 index
        int next_bottom;
        int next_east;
        int next_south;
        if(order[i]==LEFT)
        {
            next_bottom=7-east;
            next_east=bottom;
            next_south=south;
        }
        if(order[i]==RIGHT)
        {
            next_bottom=east;
            next_east=7-bottom;
            next_south=south;
        }
        if(order[i]==UP)
        {
            next_bottom=7-south;
            next_east=east;
            next_south=bottom;
        }
        if(order[i]==DOWN)
        {
            next_bottom=south;
            next_east=east;
            next_south=7-bottom;
        }
        if(next_r<0 || next_c <0 || next_r>=n || next_c>=m)//지도의 범위를 벗어나는 경우
            continue;
        r=next_r;
        c=next_c;
        south=next_south;
        bottom=next_bottom;
        east=next_east;
        if(map[r][c]==0)//이동한 칸에 쓰여있는 수가 0이면
        {
            map[r][c]=dice[bottom];//주사위 밑면의 수가 칸에 복사
        }
        else//0이 아니면
        {
            dice[bottom]=map[r][c];//칸의 수가 주사위 밑면에 복사되고
            map[r][c]=0;//칸에 쓰여있는 수는 0이 됨
        }

        printf("%d\n", dice[7-bottom]);
    }

}
