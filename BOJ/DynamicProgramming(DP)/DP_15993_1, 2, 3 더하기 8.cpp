#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://www.acmicpc.net/problem/15993 1, 2, 3 더하기 8

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    ll dp1[101010] = {}, dp2[101010] = {};
    int mod = 1e9 + 9;
    
    dp1[1] = 1;
    dp1[2] = 1;
    dp2[2] = 1;
    dp1[3] = 2;
    dp2[3] = 2;
    
    for(int i=4; i<=100000; i++) {
        dp1[i] = (dp2[i-1] + dp2[i-2] + dp2[i-3]) % mod;
        dp2[i] = (dp1[i-1] + dp1[i-2] + dp1[i-3]) % mod;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp1[n] << ' ' << dp2[n] << '\n';
    }
    
    return 0;
}
