#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <map>
#include <iomanip>
#include <list>
#include <stack>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

//https://www.acmicpc.net/problem/9466 텀 프로젝트
//dfs 사이클 찾기가 핵심!

int n;
int visit[100001];
int student[100001];
int check[100001];
int cnt;

void dfs(int cur)
{
    visit[cur] = 1; //방문 처리

    int nxt = student[cur]; //현재 학생이 가르키는 다음 학생

    if(!visit[nxt]) dfs(nxt); //방문하지 않은 학생이면 재귀
    else if(!check[nxt])
    {
        for(int i=nxt; i!=cur; i=student[i]) //사이클의 길이측정
        {
            cnt++;
        }
        cnt++; //자기 자신을 더해줌
    }
    check[cur] = 1;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;

        memset(visit, 0, sizeof(visit)); //방문 초기화
        memset(check, 0, sizeof(check)); //체크 초기화
        //다 입력 받음
        for(int i=1; i<=n; i++)
        {
            cin >> student[i];
        }

        cnt = 0;
        for(int i=1; i<=n; i++)
        {
            if(visit[i]) continue;
            dfs(i);
        }
        cout << n - cnt << '\n';
    }

    return 0;
}

