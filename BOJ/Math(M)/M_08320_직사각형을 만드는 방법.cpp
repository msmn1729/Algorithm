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
    int dp[10001] = {};
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i=3; i<=n; i++) {
        dp[i] = dp[i-1];
        for(int j=1; j<=sqrt(i); j++) {
            if(i%j == 0) dp[i]++;
        }
    }
    cout << dp[n];

    return 0;
}
