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

//https://www.acmicpc.net/problem/1600 말이 되고픈 원숭이
//BFS 응용문제

int board[200][200];
int dist[200][200][31]; //최대 말 점프 횟수 30
int dx[12] = {-1, 0, 1, 0, -2, -2, -1, -1, 1, 1, 2, 2};
int dy[12] = {0, 1, 0, -1, -1, 1, -2, 2, -2, 2, -1, 1};

struct location
{
    int x, y, z;
};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int k, r, c; //k번만 말처럼 이동가능
    cin >> k;
    cin >> c >> r;
    int i, j;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            cin >> board[i][j];
        }
    }
    
    //BFS
    queue<location> q;
    q.push({0, 0, 0});
    board[0][0] = 1; //시작점 벽처리
    
    while(q.size())
    {
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        q.pop();
        
        int end_idx = 4;
        if(z < k) end_idx += 8; //말처럼 이동도 가능할 때
        if(x == r-1 && y == c-1) //종료 지점에 도착
        {
            cout << dist[x][y][z];
            return 0;
        }
        for(int dir=0; dir<end_idx; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z;
            if(dir >= 4) nz++; //말처럼 이동하는 경우 카운트 증가
            if(nx<0 || ny<0 || nx>=r || ny>=c) continue;
            if(dist[nx][ny][nz] || board[nx][ny]) continue; //방문했었거나 벽이면 패스
            dist[nx][ny][nz] = dist[x][y][z] + 1;
            q.push({nx, ny, nz});
        }
    }
    cout << -1;

    return 0;
}
