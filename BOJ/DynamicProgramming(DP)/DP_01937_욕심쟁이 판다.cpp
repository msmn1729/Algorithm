#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://www.acmicpc.net/problem/1937 욕심쟁이 판다

int n;
int board[501][501];
int dp[501][501];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(int x, int y) {
    int &ret = dp[x][y];
    if(ret) return ret;
    
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
        if(board[x][y] >= board[nx][ny]) continue;
        ret = max(ret, dfs(nx, ny) + 1);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cin >> board[i][j];
    }

    int ans = 1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) ans = max(ans, dfs(i, j));
    }
    cout << ans;

    return 0;
}
