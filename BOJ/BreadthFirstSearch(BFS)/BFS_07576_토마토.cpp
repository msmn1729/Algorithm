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

//https://www.acmicpc.net/problem/7576 토마토

int board[1002][1002];
int dist[1002][1002];

int n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;
    int i, j, ans=0;
    queue<pair<int, int> > Q;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 1) //토마토면
            {
                Q.push({i, j}); //토마토의 좌표들을 큐에 저장
            }
            else if(board[i][j] == 0) //안익은 토마토면
            {
                dist[i][j] = -1; //가야할 곳
            }
        }
    }

    while(!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        for(int div=0; div<4; div++)
        {
            int nx = cur.first + dx[div];
            int ny = cur.second + dy[div];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny] >= 0) continue; //방문했었거나(dist>0) 토마토가 없는 곳(dist==0)이면 패스
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            ans = max(ans, dist[nx][ny]);
            Q.push({nx, ny});
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(dist[i][j] == -1) //안익은 토마토가 남아있으면
            {
                cout << -1;
                return 0;
            }
        }
    }
    cout << ans;
}
