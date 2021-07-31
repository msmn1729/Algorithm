#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/15486 퇴사 2

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    int dp[1502001] = {};
    cin >> n;
    for(int i=0; i<n; i++) {
        int t, p;
        cin >> t >> p;
        dp[i + t] = max(dp[i + t], dp[i] + p);
        dp[i + 1] = max(dp[i + 1], dp[i]);
    }
    cout << dp[n];
    
    return 0;
}
