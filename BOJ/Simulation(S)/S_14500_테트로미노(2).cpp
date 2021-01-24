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

using namespace std;

//https://www.acmicpc.net/problem/14500 테트로미노

int ar[501][501];
int visit[501][501];
int r, c;
int ans = -2e9;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs(int x, int y, int length, int sum) {
    if(x<0 || y<0 || x>=r || y>=c || visit[x][y]) return;
    sum += ar[x][y];
    if(length >= 4) {
        ans = max(ans, sum);
        return;
    }
    
    visit[x][y] = 1;
    for(int i=0; i<4; i++) dfs(x+dx[i], y+dy[i], length+1, sum);
    visit[x][y] = 0;
}

void solve() {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            dfs(i, j, 1, 0);
            if(i) {
                visit[i-1][j] = visit[i+1][j] = 1;
                dfs(i, j, 3, ar[i-1][j] + ar[i+1][j]);
                visit[i-1][j] = visit[i+1][j] = 0;
            }
            if(j) {
                visit[i][j-1] = visit[i][j+1] = 1;
                dfs(i, j, 3, ar[i][j-1] + ar[i][j+1]);
                visit[i][j-1] = visit[i][j+1] = 0;
            }
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int i, j;
    cin >> r >> c;
    for(i=0; i<r; i++) for(j=0; j<c; j++) cin >> ar[i][j];
    solve();
    
    return 0;
}
