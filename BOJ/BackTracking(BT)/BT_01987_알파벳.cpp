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

//https://www.acmicpc.net/problem/1987 알파벳

int r, c;
char board[25][25];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
bool alpa[26];
int ans;

void dfs(int x, int y, int cnt) {
    ans = max(ans, cnt);
    
    for(int dir=0; dir<4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        int nc = board[nx][ny] - 'A';
        if(nx<0 || ny<0 || nx>=r || ny>=c) continue;
        if(alpa[nc]) continue;
        
        alpa[nc] = true;
        dfs(nx, ny, cnt+1);
        alpa[nc] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> r >> c;
    for(int i=0; i<r; i++) cin >> board[i];
    alpa[board[0][0] - 'A'] = true;
    dfs(0, 0, 1);
    cout << ans;
    
    return 0;
}
