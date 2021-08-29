#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://www.acmicpc.net/problem/11170 0의 개수

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    
    int dp[1010101] = {1};
    for(int i=1; i<=1000000; i++) {
        string s = to_string(i);
        int cnt = 0;
        for(char c : s) {
            if(c == '0') cnt++;
        }
        dp[i] = dp[i-1] + cnt;
    }
    
    while(t--) {
        int n, m;
        cin >> n >> m;
        if(n == 0) cout << dp[m] << '\n';
        else cout << dp[m] - dp[n-1] << '\n';
    }
    
    return 0;
}
