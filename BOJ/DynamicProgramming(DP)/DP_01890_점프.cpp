#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/1890 점프

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int ar[101][101] = {};
    ll dp[101][101] = {1, };
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cin >> ar[i][j];
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int val = ar[i][j];
            if(val == 0) continue;
            if(i+val < n) dp[i+val][j] += dp[i][j];
            if(j+val < n) dp[i][j+val] += dp[i][j];
        }
    }
    cout << dp[n-1][n-1];
    return 0;
}
