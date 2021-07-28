#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/16918 봄버맨

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int ar[202][202], bomb_ar[202][202];
int r, c, n;

void bfs() {
    queue<pii> q;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            bomb_ar[i][j] = 1;
            if(ar[i][j]) {
                bomb_ar[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    
    while(q.size()) {
        int x = q.front().first;
        int y = q.front().second; q.pop();
        
        for(int dir=0; dir<4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx<0 || ny<0 || nx>=r || ny>=c) continue;
            bomb_ar[nx][ny] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> r >> c >> n;
    for(int i=0; i<r; i++) {
        string s;
        cin >> s;
        if(n == 1) cout << s << '\n'; // n이 1일 때 그대로 출력
        for(int j=0; j<c; j++) {
            bomb_ar[i][j] = 1;
            if(s[j] == 'O') ar[i][j] = 1;
        }
    }
    if(n == 1) return 0;
    
    // n이 짝수일 때는 전부 폭탄
    if(n % 2 == 0) {
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                cout << 'O';
            }
            cout << '\n';
        }
    }
    else {
        n = (n - 1) / 2;
        while(n--) {
            bfs();
            for(int i=0; i<r; i++) {
                for(int j=0; j<c; j++) {
                    ar[i][j] = bomb_ar[i][j];
                }
            }
        }
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(bomb_ar[i][j]) cout << 'O';
                else cout << '.';
            }
            cout << '\n';
        }
    }
    return 0;
}
