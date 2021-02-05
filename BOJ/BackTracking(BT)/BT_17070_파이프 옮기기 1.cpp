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
#include <unordered_map>
#include <bitset>
#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/17070 파이프 옮기기 1

int n;
int board[20][20] = {};
int dx[3] = {0, 1, 1};
int dy[3] = {1, 0, 1};
int ans;

void solve(int x, int y, int cur_type) {
    if(x == n && y == n) {
        ans++;
        return;
    }
    for(int nxt_type=0; nxt_type<3; nxt_type++) {
        if(cur_type + nxt_type == 1) continue; //가로 <-> 세로는 패스
        int nx = x + dx[nxt_type];
        int ny = y + dy[nxt_type];
        if(nx>n || ny>n || board[nx][ny]) continue;
        if(nxt_type == 2 && (board[x+1][y] || board[x][y+1])) continue; //대각파이프로 넘어갈 때 예외처리
        solve(nx, ny, nxt_type);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin >> board[i][j];
    solve(1, 2, 0);
    cout << ans;
    
    return 0;
}
