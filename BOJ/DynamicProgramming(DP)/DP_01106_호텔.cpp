#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/1106 호텔

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int c, n;
    cin >> c >> n;
    vector<pii> v(n);
    for(int i=0; i<n; i++) cin >> v[i].first >> v[i].second;
    
    int dp[2020] = {}; // dp[a] : 적어도 a명 이상 늘리기 위한 최소비용
    c += 100; // 예외처리
    
    for(int i=1; i<=c; i++) {
        int mn = 2e9;
        for(auto &[cost, member] : v) {
            if(i - member < 0) continue;
            mn = min(mn, dp[i - member] + cost);
        }
        dp[i] = mn;
    }
    
    for(int i=1; i<=c; i++) {
        for(int j=i+1; j<=c; j++) {
            dp[i] = min(dp[i], dp[j]);
        }
    }
    cout << dp[c - 100];
    
    return 0;
}
