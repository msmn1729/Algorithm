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

//https://www.acmicpc.net/problem/7562 나이트의 이동

int dist[301][301] = {};
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t, n, i;
    int sx, sy, ex, ey;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=0; i<n; i++) fill(dist[i], dist[i]+n, -1);
        cin >> sx >> sy >> ex >> ey;
        
        queue<pair<int, int> > q;
        q.push({sx, sy});
        dist[sx][sy] = 0;
        
        while(q.size())
        {
            auto cur = q.front(); q.pop();
            if(cur.first == ex && cur.second == ey)
            {
                cout << dist[cur.first][cur.second] << '\n';
                break;
            }
            for(int dir=0; dir<8; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx == ex && ny == ey)
                {
                }
                if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
                if(dist[nx][ny] >= 0) continue;
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    return 0;
}
