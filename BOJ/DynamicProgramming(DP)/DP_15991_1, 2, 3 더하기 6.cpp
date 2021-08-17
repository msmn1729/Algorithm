#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://www.acmicpc.net/problem/15991 1, 2, 3 더하기 6

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    ll dp[101010] = {};
    int mod = 1e9 + 9;
    
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 2;
    dp[4] = 3;
    dp[5] = 3;
    
    for(int i=6; i<=100000; i++) {
        dp[i] = dp[i-2] + dp[i-4] + dp[i-6];
        dp[i] %= mod;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
    
    return 0;
}
