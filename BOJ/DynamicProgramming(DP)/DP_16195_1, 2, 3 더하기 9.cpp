#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://www.acmicpc.net/problem/16195 1, 2, 3 더하기 9

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    ll dp[1010][1010] = {};
    ll mod = 1e9 + 9;
    
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 2;
    dp[3][3] = 1;
    
    for(int i=4; i<=1000; i++) {
        for(int j=1; j<=i; j++) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-2][j-1] + dp[i-3][j-1]) % mod;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int ans = 0;
        for(int i=1; i<=m; i++) {
            ans += dp[n][i];
            ans %= mod;
        }
        cout << ans << '\n';
    }
    
    return 0;
}
