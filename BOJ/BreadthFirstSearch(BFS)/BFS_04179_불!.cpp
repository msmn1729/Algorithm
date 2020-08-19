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

//https://www.acmicpc.net/problem/4179 불!
//BFS 활용을 잘해야함

using namespace std;
string board[1002];
int fire_dist[1002][1002]; //불의 전파 시간
int JH_dist[1002][1002]; //지훈이의 이동 시간

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int i, j, r, c;
    cin >> r >> c;
    
    for(i=0; i<r; i++)
    {
        fill(fire_dist[i], fire_dist[i]+c, -1);
        fill(JH_dist[i], JH_dist[i]+c, -1);
    }
    
    for(i=0; i<r; i++)
    {
        cin >> board[i];
    }
    
    queue<pair<int, int>> fire_q, JH_q;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(board[i][j] == 'F') //불의 좌표 저장
            {
                fire_q.push({i, j});
                fire_dist[i][j] = 0;
            }
            if(board[i][j] == 'J') //지훈이 좌표 저장
            {
                JH_q.push({i, j});
                JH_dist[i][j] = 0;
            }
        }
    }
    
    //불 BFS
    while(!fire_q.empty())
    {
        auto cur = fire_q.front(); fire_q.pop();
        for(i=0; i<4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx<0 || ny<0 || nx>=r || ny>=c) continue;
            if(board[nx][ny] == '#' || fire_dist[nx][ny] >= 0) continue;
            fire_dist[nx][ny] = fire_dist[cur.first][cur.second] + 1;
            fire_q.push({nx, ny});
        }
    }
    //지훈이 BFS
    while(!JH_q.empty())
    {
        auto cur = JH_q.front(); JH_q.pop();
        for(i=0; i<4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx<0 || ny<0 || nx>=r || ny>=c)
            {
                cout << JH_dist[cur.first][cur.second] + 1;
                return 0; //큐에 거리 순으로 들어가므로 처음 것만 출력하고 종료
            }
            if(board[nx][ny] == '#' || JH_dist[nx][ny] >= 0) continue;
            if((0 <= fire_dist[nx][ny])
               && (fire_dist[nx][ny] <= JH_dist[cur.first][cur.second] + 1))
            {
                continue;
            }
            
            JH_dist[nx][ny] = JH_dist[cur.first][cur.second] + 1;
            JH_q.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE";
    
    return 0;
}
