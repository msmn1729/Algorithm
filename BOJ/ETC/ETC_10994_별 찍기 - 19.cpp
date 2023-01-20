#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

char board[501][501];

void drawStar(int size, int x, int y) {
    if(size == 1) {
        board[x][y] = '*';
        return;
    }
    
    int len = 4 * (size - 1) + 1;
    for(int i=x; i<x + len; i++) {
        board[i][y] = '*';
        board[i][y + len - 1] = '*';
    }
    
    for(int i=y; i<y + len; i++) {
        board[x][i] = '*';
        board[x + len - 1][i] = '*';
    }
    
    drawStar(size - 1, x + 2, y + 2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    int len = 4 * (n - 1) + 1;
    
    for(int i=0; i<len; i++) {
        for(int j=0; j<len; j++) {
            board[i][j] = ' ';
        }
    }
    
    drawStar(n, 0, 0);
    
    for(int i=0; i<len; i++) {
        for(int j=0; j<len; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
        
    return 0;
}
