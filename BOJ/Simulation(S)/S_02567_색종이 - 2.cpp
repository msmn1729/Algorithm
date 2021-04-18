#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <iomanip>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define ll long long
#define INF 1e9

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    int board[105][105] = {};
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    cin >> n;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        for(int j=0; j<10; j++) {
            for(int k=0; k<10; k++) {
                board[a+j][b+k] = 1;
            }
        }
    }

    int ans = 0;
    for(int i=1; i<=100; i++) {
        for(int j=1; j<=100; j++) {
            if(board[i][j] == 1) {
                for(int dir=0; dir<4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if(!board[nx][ny]) ans++;
                }
            }
        }
    }
    cout << ans;
    
    return 0;
}
