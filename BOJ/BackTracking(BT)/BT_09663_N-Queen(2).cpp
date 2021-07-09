#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://www.acmicpc.net/problem/9663 N-Queen

int n, ans;
int vis[3][30]; // 세로, 대각, 역대각

void go(int x) {
    if(x == n) {
        ans++;
        return;
    }
    for(int y=0; y<n; y++) {
        if(vis[0][y] || vis[1][x-y+n-1] || vis[2][x+y]) continue;
        vis[0][y] = vis[1][x-y+n-1] = vis[2][x+y] = 1;
        go(x + 1);
        vis[0][y] = vis[1][x-y+n-1] = vis[2][x+y] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    go(0);
    cout << ans;
    return 0;
}
