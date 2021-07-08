#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
// https://www.acmicpc.net/problem/1103 게임

int r, c;
char board[51][51];
int max_dist[51][51];
int visited[51][51];
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int dfs(int x, int y) {
    if(x<0 || y<0 || x>=r || y>=c || board[x][y] == 'H') return 0;
    if(visited[x][y]) {
        cout << -1;
        exit(0);
    }
    
    int &ret = max_dist[x][y];
    if(ret) return ret;
    visited[x][y] = 1;
    
    for(int dir=0; dir<4; dir++) {
        int nx = x + dx[dir] * (board[x][y] - '0');
        int ny = y + dy[dir] * (board[x][y] - '0');
        ret = max(ret, dfs(nx, ny) + 1);
    }
    
    visited[x][y] = 0;
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> r >> c;
    for(int i=0; i<r; i++) cin >> board[i];
    cout << dfs(0, 0);
    
    return 0;
}
