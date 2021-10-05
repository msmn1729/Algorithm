#include <iostream>
#include <cmath>
#include <queue>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    string ar[501] = {};
    int r, c;
    cin >> r >> c;
    
    for(int i=0; i<r; i++) {
        cin >> ar[i];
    }
    
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(ar[i][j] == 'S') {
                for(int dir=0; dir<4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if(nx<0 || ny<0 || nx>=r || ny>=c) continue;
                    if(ar[nx][ny] == 'W') {
                        cout << 0;
                        return 0;
                    }
                }
            }
        }
    }
    
    cout << 1 << '\n';
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(ar[i][j] == '.') cout << 'D';
            else cout << ar[i][j];
        }
        cout << '\n';
    }

    return 0;
}
