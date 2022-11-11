#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

typedef struct {
    int x, y;
} info;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int board[101][101];
int brokenWall[101][101]; // 해당 좌표 도달하는데 가장 적게 부순 벽의 수

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int c, r;
    cin >> c >> r;
    string s;
    
    for(int i=0; i<r; i++) {
        cin >> s;
        for(int j=0; j<c; j++) {
            board[i][j] = s[j] - '0';
            brokenWall[i][j] = INF;
        }
    }
    
    queue<info> q;
    q.push({0, 0});
    brokenWall[0][0] = 0;
    
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        
        for(int dir=0; dir<4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx<0 || nx>=r || ny<0 || ny>=c) continue;
            
            // 벽인 경우
            if(board[nx][ny]) {
                // 벽을 부수는게 이득이 아닌 경우 패스
                if(brokenWall[x][y]+1 >= brokenWall[nx][ny]) continue;
                brokenWall[nx][ny] = brokenWall[x][y]+1;
                q.push({nx, ny});
                
            }
            else {
                if(brokenWall[x][y] >= brokenWall[nx][ny]) continue;
                brokenWall[nx][ny] = brokenWall[x][y];
                q.push({nx, ny});
            }
        }
    }
    cout << brokenWall[r-1][c-1];
    
    return 0;
}
