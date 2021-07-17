#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
// https://www.acmicpc.net/problem/1932 정수 삼각형

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int dp[501][501] = {};
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            cin >> dp[i][j];
            dp[i][j] += max(dp[i-1][j-1], dp[i-1][j]);
        }
    }
    int ans = 0;
    for(int j=1; j<=n; j++) ans = max(ans, dp[n][j]);
    cout << ans;
    
    return 0;
}
