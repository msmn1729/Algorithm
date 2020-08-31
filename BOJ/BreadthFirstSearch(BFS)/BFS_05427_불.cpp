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

//https://www.acmicpc.net/problem/5427 불
//브랜디 코딩대회 2번문제와 유사

int r, c;
char board[1001][1001];
int fire_visit[1001][1001];
int man_visit[1001][1001];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, i, j;
    cin >> t;
    
    while(t--)
    {
        cin >> c >> r;
        
        //가야할 곳들 -1 처리
        for(i=0; i<r; i++)
        {
            fill(fire_visit[i], fire_visit[i]+c, -1);
            fill(man_visit[i], man_visit[i]+c, -1);
        }
    
        queue<pair<int, int> > q, q2;
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                cin >> board[i][j];
                if(board[i][j] == '@') //상근이 위치
                {
                    q.push({i, j});
                    man_visit[i][j] = 0;
                }
                else if(board[i][j] == '*') //불난 곳들의 위치
                {
                    q2.push({i, j});
                    fire_visit[i][j] = 0;
                }
            }
        }
        
        //불 bfs
        while(q2.size())
        {
            auto cur = q2.front(); q2.pop();
            for(int dir=0; dir<4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx<0 || ny<0 || nx>=r || ny>=c) continue;
                if(board[nx][ny] == '#' || fire_visit[nx][ny] >= 0) continue; //벽이거나 방문한 곳이면 패스
                fire_visit[nx][ny] = fire_visit[cur.first][cur.second] + 1;
                q2.push({nx, ny});
            }
        }
        
        int flag = 0;
        //상근이 bfs
        while(q.size())
        {
            if(flag) break;
            auto cur = q.front(); q.pop();
            for(int dir=0; dir<4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx<0 || ny<0 || nx>=r || ny>=c)
                {
                    cout << man_visit[cur.first][cur.second] + 1 << '\n';
                    flag = 1;
                    break;
                }
                if(board[nx][ny] == '#' || man_visit[nx][ny] >= 0) continue; //벽이거나 방문한 곳이면 패스
                if(man_visit[cur.first][cur.second] + 1 >= fire_visit[nx][ny]
                   && fire_visit[nx][ny] >= 0) continue;
                man_visit[nx][ny] = man_visit[cur.first][cur.second] + 1;
                q.push({nx, ny});
            }
        }
        if(!flag) cout << "IMPOSSIBLE\n";
    }
    
    return 0;
}
