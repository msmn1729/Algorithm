#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
// https://www.acmicpc.net/problem/1103 게임

int r, c, ans = -1;
int board[51][51] = {};
int max_dist[51][51] = {};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int limit;

void dfs(int x, int y, int depth) {
    if(ans > limit) return;
    ans = max(ans, depth);
    if(x<0 || y<0 || x>=r || y>=c || board[x][y] == -1) return;
    if(depth <= max_dist[x][y]) return; // 횟수가 이미 더 큰경우 패스
    
    max_dist[x][y] = depth;
    for(int dir=0; dir<4; dir++) {
        int nx = x + dx[dir] * board[x][y];
        int ny = y + dy[dir] * board[x][y];
        dfs(nx, ny, depth+1);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> r >> c;
    limit = r*c; // 최대 깊이
    string s;
    
    for(int i=0; i<r; i++) {
        cin >> s;
        for(int j=0; j<c; j++) {
            if(s[j] == 'H') board[i][j] = -1;
            else board[i][j] = s[j] - '0';
        }
    }
    for(int i=0; i<r; i++) fill(max_dist[i], max_dist[i] + c, -1);
    dfs(0, 0, 0);
    
    if(ans > limit) ans = -1;
    cout << ans;
    return 0;
}
