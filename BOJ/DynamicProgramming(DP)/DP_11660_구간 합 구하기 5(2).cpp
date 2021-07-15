#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
// https://www.acmicpc.net/problem/11660 구간 합 구하기 5

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    int dp[1030][1030] = {};
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> dp[i][j];
            dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
    while(m--) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        cout << dp[ex][ey] - dp[sx-1][ey] - dp[ex][sy-1] + dp[sx-1][sy-1] << '\n';
    }
    
    return 0;
}
