#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/10844 쉬운 계단 수

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    ll dp[101][10] = {}; // dp[a][b]: a길이 숫자이고 마지막 숫자가 b일 때의 경우의 수
    
    for(int j=1; j<=9; j++) dp[1][j] = 1;
    for(int i=2; i<=n; i++) {
        for(int j=0; j<=9; j++) {
            if(j-1 >= 0) dp[i][j] += dp[i-1][j-1];
            if(j+1 <= 9) dp[i][j] += dp[i-1][j+1];
        }
    }
    
    ll ans = 0;
    for(int i=0; i<=9; i++) {
        ans += dp[n][i];
        ans %= 1000000000;
    }
    cout << ans;
    
    return 0;
}
