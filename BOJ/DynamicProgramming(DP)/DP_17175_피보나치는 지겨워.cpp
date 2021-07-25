#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/17175 피보나치는 지겨워

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    ll dp[51] = {1, 1};
    for(int i=2; i<=n; i++) {
        dp[i] = 1 + dp[i-2] + dp[i-1];
        dp[i] %= 1000000007;
    }
    cout << dp[n];
    
    return 0;
}
