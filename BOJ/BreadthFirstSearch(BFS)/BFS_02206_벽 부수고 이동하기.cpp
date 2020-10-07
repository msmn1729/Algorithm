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

struct loc
{
    int x, y, z;
};

int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
int board[1001][1001] = {};
int dist[1001][1001][2] = {}; //마지막 인덱스는 부순 벽의 개수

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    
    int r, c, i, j;
    scanf("%d %d", &r, &c);
    
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            scanf("%1d", &board[i][j]);
        }
    }
    queue<loc> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 1;
    while(q.size())
    {
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z; q.pop();
        
        if(x == r-1 && y == c-1)
        {
            printf("%d\n", dist[x][y][z]);
            return 0;
        }
        for(i=0; i<4; i++)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            
            if(nx<0 || ny<0 || nx>=r || ny>=c) continue;
            if(dist[nx][ny][z]) continue; //방문했거나 패스
            
            if(board[nx][ny] == 0) //벽이 아닐 때는 벽 부숨 여부가 상관없음
            {
                dist[nx][ny][z] = dist[x][y][z] + 1;
                q.push({nx, ny, z});
            }
            else if(board[nx][ny] && !z) //벽을 처음 부술 때
            {
                dist[nx][ny][z+1] = dist[x][y][z] + 1;
                q.push({nx, ny, z+1});
            }
        }
    }
    puts("-1");
    return 0;
}

