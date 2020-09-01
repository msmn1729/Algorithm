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

//https://www.acmicpc.net/problem/2206 벽 부수고 이동하기
//페어, 튜플, 구조체
//dist를 정의할 때 고민해보자

string board[1001];
int dist[1001][1001][2];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int r, c;

struct location
{
    int x, y, w;
};

int bfs()
{
    queue<location> q;
    q.push({0, 0, 0}); //시작좌표
    dist[0][0][0] = 1; //방문처리
    
    while(q.size())
    {
        auto cur = q.front(); q.pop();
        int x = cur.x, y = cur.y, w = cur.w;
        if(x+1 == r && y+1 == c) return dist[x][y][w]; //도착점에 도달하면 정답 반환
        
        for(int dir=0; dir<4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx<0 || ny<0 || nx>=r || ny>=c) continue;
            if(dist[nx][ny][w]) continue; //방문한 곳은 패스
            if(board[nx][ny] == '0') //빈 곳인 경우는 이전의 벽 부숨 여부가 상관없음
            {
                dist[nx][ny][w] = dist[x][y][w] + 1;
                q.push({nx, ny, w});
            }
            if(board[nx][ny] == '1' && w == 0) //처음 벽을 부시는 경우
            {
                dist[nx][ny][1] = dist[x][y][w] + 1;
                q.push({nx, ny, 1});
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
    
    cin >> r >> c;
    int i;
    for(i=0; i<r; i++) cin >> board[i];
    cout << bfs();
    
    return 0;
}
