#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/14501 퇴사

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    int dp[20] = {};
    cin >> n;
    for(int i=0; i<n; i++) {
        int t, p;
        cin >> t >> p;
        dp[i+t] = max(dp[i+t], dp[i] + p);
        dp[i+1] = max(dp[i+1], dp[i]); // 위아래 순서 바뀌어도 무방
    }
    cout << dp[n];
    
    return 0;
}
