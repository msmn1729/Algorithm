#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://www.acmicpc.net/problem/15992 1, 2, 3 더하기 7

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    ll dp[1010][1010] = {};
    int mod = 1e9 + 9;
    
    dp[0][0] = 1;
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    
    for(int i=3; i<=1000; i++) {
        for(int j=1; j<=i; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-2][j-1] + dp[i-3][j-1];
            dp[i][j] %= mod;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << dp[n][m] << '\n';
    }
    
    return 0;
}
