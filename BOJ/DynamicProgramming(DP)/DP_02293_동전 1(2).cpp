#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/2293 동전 1

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    int dp[10101] = {1};
    
    for(int i=0; i<n; i++) {
        int coin;
        cin >> coin;
        for(int j=coin; j<=k; j++) dp[j] += dp[j-coin];
    }
    cout << dp[k];
    
    return 0;
}
