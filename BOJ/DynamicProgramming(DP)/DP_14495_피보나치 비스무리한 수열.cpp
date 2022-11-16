#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    ll dp[200] = {0, 1, 1, 1};

    for(int i=4; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-3];
    }
    cout << dp[n];
    
    return 0;
}
