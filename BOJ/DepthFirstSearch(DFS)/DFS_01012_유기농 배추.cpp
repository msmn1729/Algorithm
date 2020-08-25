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

//https://www.acmicpc.net/problem/1012 유기농 배추
//bfs, dfs 모두 풀이 가능!
//dfs 풀이가 더 간단하다 ~.~

int board[51][51];
int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y)
{
    if(x < 0 || y < 0 || x >= n || y >= m || board[x][y] == 0) return;
    board[x][y] = 0;
    for(int i=0; i<4; i++)
    {
        dfs(x+dx[i], y+dy[i]);
    }
}

void bfs(int x, int y)
{
    queue<pair<int, int> > q;
    q.push({x, y});
    board[x][y] = 0;
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        for(int i=0; i<4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(board[nx][ny] == 0) continue;
            board[nx][ny] = 0;
            q.push({nx, ny});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t, k, x, y, i, j;
    cin >> t;
    while(t--)
    {
        cin >> m >> n >> k;
        while(k--)
        {
            cin >> y >> x;
            board[x][y] = 1;
        }
        
        int ans = 0;
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(board[i][j])
                {
                    ans++;
                    dfs(i, j);
//                    bfs(i, j);
                }
            }
        }
        cout << ans << '\n';
    }
    
    
    return 0;
}
