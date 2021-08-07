#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/11057 오르막 수

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    // dp[a][b] : a자리수이고 b로 끝날 때 오르막 수의 개수
    int dp[1010][10] = {};
    int n; cin >> n;
    
    for(int j=0; j<=9; j++) dp[1][j] = 1;
    
    for(int i=2; i<=n; i++) {
        for(int j=0; j<=9; j++) {
            for(int k=0; k<=j; k++) {
                dp[i][j] += dp[i-1][k];
                dp[i][j] %= 10007;
            }
        }
    }
    
    int ans = 0;
    for(int j=0; j<=9; j++) ans += dp[n][j];
    cout << ans % 10007;
    
    return 0;
}
