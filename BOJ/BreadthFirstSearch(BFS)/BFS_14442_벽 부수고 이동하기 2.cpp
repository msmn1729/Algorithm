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

int board[1001][1001];
int dist[1001][1001][11];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct location
{
    int x, y, z;
};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int r, c, k, i, j;
    char ch;
    cin >> r >> c >> k;
    
    for(i=1; i<=r; i++)
    {
        for(j=1; j<=c; j++)
        {
            cin >> ch;
            board[i][j] = ch - '0';
        }
    }
    
    //BFS
    queue<location> q;
    q.push({1, 1, 0});
    board[1][1] = 1;
    dist[1][1][0] = 1;
    
    while(q.size())
    {
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z; q.pop();
        
        
        if(x == r && y == c) //도착시 종료
        {
            cout << dist[x][y][z];
            return 0;
        }
        
        for(int dir=0; dir<4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z;
            if(nx<1 || ny<1 || nx>r || ny>c) continue;
            if(dist[nx][ny][nz]) continue;
            if(board[nx][ny] == 0) //벽이 아니면 부순횟수가 증가하지 않음
            {
                dist[nx][ny][nz] = dist[x][y][z] + 1;
                q.push({nx, ny, nz});
            }
            else if(board[nx][ny] == 1 && z < k) //벽이면서 깰 수 있는 횟수가 남아있으면
            {
                nz = z + 1;
                dist[nx][ny][nz] = dist[x][y][z] + 1; //깬다
                q.push({nx, ny, nz});
            }
        }
        
    }
    cout << "-1";

    return 0;
}
