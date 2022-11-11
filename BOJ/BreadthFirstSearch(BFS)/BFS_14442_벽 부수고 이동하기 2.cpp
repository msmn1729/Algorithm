#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

typedef struct {
    int x, y, z;
} info;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int board[1001][1001];
int dist[1001][1001][11];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int r, c, k;
    cin >> r >> c >> k;
    string s;
    
    for(int i=0; i<r; i++) {
        cin >> s;
        for(int j=0; j<c; j++) {
            board[i][j] = s[j] - '0';
        }
    }
    
    queue<info> q;
    q.push({0, 0});
    dist[0][0][0] = 1;
    
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        q.pop();
        
        if(x == r-1 && y == c-1) {
            cout << dist[x][y][z];
            return 0;
        }
        
        for(int dir=0; dir<4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx<0 || nx>=r || ny<0 || ny>=c) continue;

            if(board[nx][ny] == 0) {
                if(dist[nx][ny][z]) continue;
                dist[nx][ny][z] = dist[x][y][z]+1;
                q.push({nx, ny, z});
            }
            else if(board[nx][ny] && z < k) {
                if(dist[nx][ny][z+1]) continue;
                dist[nx][ny][z+1] = dist[x][y][z]+1;
                q.push({nx, ny, z+1});
            }
        }
    }
    cout << -1;
    
    return 0;
}
