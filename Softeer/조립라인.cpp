#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    int ar[1001][4] = {}, dp[1001][2] = {};
    cin >> n;
    
    for(int i=1; i<=n-1; i++) {
        for(int j=0; j<4; j++) cin >> ar[i][j];
    }
    cin >> ar[n][0] >> ar[n][1];
    
    dp[1][0] = ar[1][0];
    dp[1][1] = ar[1][1];
    for(int i=2; i<=n; i++) {
        dp[i][0] = min(dp[i-1][0], dp[i-1][1] + ar[i-1][3]) + ar[i][0];
        dp[i][1] = min(dp[i-1][0] + ar[i-1][2], dp[i-1][1]) + ar[i][1];
    }
    
    int ans = min(dp[n][0], dp[n][1]);
    cout << ans;

    return 0;
}
