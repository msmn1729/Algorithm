#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/11052 카드 구매하기

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    int ar[1010] = {};
    int dp[1010] = {};
    cin >> n;
    for(int i=1; i<=n; i++) cin >> ar[i];
    
    for(int i=1; i<=n; i++) {
        int mx = 0;
        for(int j=1; j<=i; j++) {
            mx = max(mx, dp[i - j] + ar[j]);
        }
        dp[i] = mx;
    }
    cout << dp[n];
    
    return 0;
}
