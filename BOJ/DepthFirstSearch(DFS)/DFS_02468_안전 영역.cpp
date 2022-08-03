#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#define ll long long
using namespace std;

int n;
int board[101][101];
int origin_board[101][101];

void dfs(int rain, int x, int y) {
    if(x<0 || y<0 || x>=n || y>=n || board[x][y]<=rain) return;
    board[x][y] = 0;
    dfs(rain, x+1, y);
    dfs(rain, x, y+1);
    dfs(rain, x-1, y);
    dfs(rain, x, y-1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> origin_board[i][j];
        }
    }
    
    int ans = 1;
    for(int rain=1; rain<=100; rain++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                board[i][j] = origin_board[i][j];
            }
        }
        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] <= rain) continue;
                dfs(rain, i, j);
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans;
    
    return 0;
}
