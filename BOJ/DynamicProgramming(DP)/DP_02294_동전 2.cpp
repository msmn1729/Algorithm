#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/2294 동전 2

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    int dp[10101] = {};
    for(int i=1; i<=k; i++) dp[i] = 2e9;
    
    for(int i=1; i<=n; i++) {
        int coin;
        cin >> coin;
        for(int j=coin; j<=k; j++) dp[j] = min(dp[j], dp[j-coin] + 1);
    }
    if(dp[k] == 2e9) cout << -1 << '\n';
    else cout << dp[k] << '\n';
    
    return 0;
}
