#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://www.acmicpc.net/problem/15989 1, 2, 3 더하기 4

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    ll dp[10101] = {1};
    
    for(int i=1; i<=3; i++) {
        for(int j=i; j<=10000; j++) {
            dp[j] += dp[j-i];
        }
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
