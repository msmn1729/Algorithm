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
using namespace std;

//https://www.acmicpc.net/problem/15683 감시
//첫 시뮬레이션
//구현하며 고려해야할 부분이 많음

#define X first
#define Y second
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int board1[10][10];
int board2[10][10];
vector<pair<int, int> > cctv;

bool OOB(int a, int b) //배열인덱스 범위 체크
{
    return a < 0 || a >= n || b < 0 || b >= m;
}
void upd(int x, int y, int dir)
{
    dir %= 4;
    while(1)
    {
        x += dx[dir];
        y += dy[dir];
        if(OOB(x, y) || board2[x][y] == 6) return; //배열 초과나 벽이면 패스
        if(board2[x][y] != 0) continue; //cctv가 있는 곳이면 패스
        board2[x][y] = 7; //cctv검사되는 지점을 7로 표시
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int i, j;
    cin >> n >> m;
    int mn = 0;
    
    //입력
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            cin >> board1[i][j];
            if(1 <= board1[i][j] && board1[i][j] <= 5) //cctv의 좌표저장
                cctv.push_back({i, j});
            if(board1[i][j] == 0) mn++;
        }
    }
    
    //4진법
    int tmp_max = 1;
    for(i=0; i<cctv.size(); i++) tmp_max *= 4;
    for(int tmp=0; tmp<tmp_max; tmp++)
    {
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                board2[i][j] = board1[i][j]; //복사
            }
        }
        int brute = tmp; //tmp값을 변경하면 안됨
        for(i=0; i<cctv.size(); i++)
        {
            int dir = brute % 4;
            brute /= 4;
            //tie로 쓸 수도 있음
            int x, y;
            tie(x, y) = cctv[i]; //cctv의 좌표
            if(board1[x][y] == 1)
            {
                upd(x, y, dir);
            }
            else if(board1[x][y] == 2)
            {
                upd(x, y, dir);
                upd(x, y, dir+2);
            }
            else if(board1[x][y] == 3)
            {
                upd(x, y, dir);
                upd(x, y, dir+1);
            }
            else if(board1[x][y] == 4)
            {
                upd(x, y, dir);
                upd(x, y, dir+1);
                upd(x, y, dir+2);
            }
            else if(board1[x][y] == 5)
            {
                upd(x, y, dir);
                upd(x, y, dir+1);
                upd(x, y, dir+2);
                upd(x, y, dir+3);
            }
        }
        int val = 0;
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                val += (board2[i][j] == 0); //사각지대 합산
            }
        }
        mn = min(mn, val);
    }
    cout << mn;
    
    return 0;
}
