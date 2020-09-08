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

//https://www.acmicpc.net/problem/14442 벽 부수고 이동하기 2

string board[1001];
int dist[1001][1001][11]; //최대 부시는 벽 10개
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int r, c, k;

struct location
{
    int x, y, z;
};

int bfs()
{
    queue<location> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 1;
    
    while(q.size())
    {
        int x = q.front().x, y = q.front().y, z = q.front().z;
        q.pop();
        
        if(x == r-1 && y == c-1) //도착시 종료
        {
            return dist[x][y][z];
        }
        
        for(int dir=0; dir<4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z;
            if(nx<0 || ny<0 || nx>=r || ny>=c) continue;
            if(dist[nx][ny][nz]) continue;
            if(board[nx][ny] == '0') //벽이 아니면 부순횟수가 증가하지 않음
            {
                dist[nx][ny][nz] = dist[x][y][z] + 1;
                q.push({nx, ny, nz});
            }
            else if(board[nx][ny] == '1' && z < k) //벽이면서 깰 수 있는 횟수가 남아있으면
            {
                nz = z + 1;
                dist[nx][ny][nz] = dist[x][y][z] + 1; //깬다
                q.push({nx, ny, nz});
            }
        }
    }
    return -1;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c >> k;
    
    for(int i=0; i<r; i++)
    {
        cin >> board[i];
    }
    cout << bfs();

    return 0;
}
