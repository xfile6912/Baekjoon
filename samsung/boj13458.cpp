#include <stdio.h>
#include <vector>

using namespace std;

int main(void)
{
    int n;//시험장의 수
    int num_of_main;//총 감도관이 감시할 수 있는 수
    int num_of_sub;//부 감독관이 감시할 수 있는 수
    scanf("%d", &n);
    
    vector<int> students(n, 0);//시험장마다 학생의 수
    for(int i=0; i<n; i++)
    {
        scanf("%d", &students[i]);
    }
    scanf("%d %d", &num_of_main, &num_of_sub);
    
    long long cnt=0;//총 감독관의 수;

    for(int i=0; i<n; i++)
    {
        cnt++;//총 감독관 한명
        int left_students=students[i]-num_of_main;
        if(left_students<=0)
            continue;
        cnt+=left_students/num_of_sub;//필요한 부감독관의 수 더해줌
        if(left_students%num_of_sub!=0)//나누어 떨어지지 않으면 부감독관 한명 더 필요
            cnt++;
    }
    printf("%lld", cnt);
}
