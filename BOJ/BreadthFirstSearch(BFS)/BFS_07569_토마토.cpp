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

//https://www.acmicpc.net/problem/7569 토마토
//bfs익히기에 좋은 문제!

int board[101][101][101];
int dist[101][101][101];
int n, m, h;
int dx[6] = {0, 0, -1, 0, 1, 0};
int dy[6] = {0, 0, 0, 1, 0, -1};
int dz[6] = {-1, 1, 0, 0, 0, 0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i, j, k;
    queue<tuple<int, int, int> > q;

    cin >> m >> n >> h;
    
    for(i=0; i<h; i++)
    {
        for(j=0; j<n; j++)
        {
            for(k=0; k<m; k++)
            {
                cin >> board[i][j][k];
                if(board[i][j][k] == 1) //토마토 좌표 저장
                {
                    q.push({i, j, k});
                }
                else if(board[i][j][k] == 0) //안 익은 토마토
                {
                    dist[i][j][k] = -1; //가야하는 곳
                }
            }
        }
    }
    
    int mx = 0;
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        for(int i=0; i<6; i++)
        {
            int nz, ny, nx;
            tie(nz, ny, nx) = cur;
            nz += dz[i];
            ny += dy[i];
            nx += dx[i];
            if(nz<0 || nz>=h || ny<0 || ny>=n || nx<0 || nx>=m) continue;
            if(dist[nz][ny][nx] >= 0) continue; //토마토가 익어있거나 없는 경우
            
            dist[nz][ny][nx] = dist[nz-dz[i]][ny-dy[i]][nx-dx[i]] + 1;
            q.push({nz, ny, nx});
            mx = max(mx, dist[nz][ny][nx]);
        }
    }
    for(i=0; i<h; i++)
    {
        for(j=0; j<n; j++)
        {
            for(k=0; k<m; k++)
            {
                if(dist[i][j][k] == -1)
                {
                    cout << -1;
                    return 0;
                }
//                cout << dist[i][j][k] << ' ';
            }
//            cout << '\n';
        }
//        cout << '\n';
    }
    cout << mx;
    
    return 0;
}
