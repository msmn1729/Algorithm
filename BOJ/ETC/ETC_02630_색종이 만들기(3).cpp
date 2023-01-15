#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int board[130][130];
int ans[2];

void solve(int size, int x, int y) {
    if(size == 0) return;
    
    int st = board[x][y];
    bool isSame = true;
    
    for(int i=x; i<x+size; i++) {
        for(int j=y; j<y+size; j++) {
            if(st == board[i][j]) continue;
            isSame = false;
            break;
        }
        if(!isSame) break;
    }
    
    if(isSame) {
        ans[st]++;
        return;
    }
    
    solve(size/2, x, y);
    solve(size/2, x + size/2, y);
    solve(size/2, x, y + size/2);
    solve(size/2, x + size/2, y + size/2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> board[i][j];
        }
    }
    
    solve(n, 0, 0);
    
    cout << ans[0] << '\n' << ans[1];
    
    return 0;
}
