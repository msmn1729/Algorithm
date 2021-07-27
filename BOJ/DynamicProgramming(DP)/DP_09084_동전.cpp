#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/9084 동전

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t, n, m;
    cin >> t;
    
    while(t--) {
        cin >> n;
        int dp[10101] = {1};
        int coin[21] = {};
        for(int i=1; i<=n; i++) cin >> coin[i];
        cin >> m;
        
        for(int i=1; i<=n; i++) {
            for(int j=coin[i]; j<=m; j++) {
                dp[j] += dp[j-coin[i]];
            }
        }
        cout << dp[m] << '\n';
    }
    
    return 0;
}
