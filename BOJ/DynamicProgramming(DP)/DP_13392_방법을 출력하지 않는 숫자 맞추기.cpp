#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <cmath>
#define ll long long
using namespace std;

int dp[10001][10];
int from[10001], to[10001];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s1, s2;
    cin >> n;
    cin >> s1 >> s2;
    
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=9; j++) {
            dp[i][j] = 1e9;
        }
    }
    
    for(int i=1; i<=n; i++) from[i] = s1[i-1] - '0';
    for(int i=1; i<=n; i++) to[i] = s2[i-1] - '0';
    
    for(int i=0; i<=9; i++) dp[0][i] = i;
    
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=9; j++) {
            int lcnt = (to[i] - j - from[i] + 20) % 10;
            int rcnt = 10 - lcnt;
            dp[i][j] = min(dp[i][j], dp[i-1][j] + rcnt);
            dp[i][(j + lcnt) % 10] = min(dp[i][(j + lcnt) % 10], dp[i-1][j] + lcnt);
        }
    }
    
//    for(int i=0; i<=n; i++) {
//        for(int j=0; j<=9; j++) {
//            cout << dp[i][j] << ' ';
//        }
//        cout << '\n';
//    }
    int ans = 2e9;
    for(int i=0; i<=9; i++) {
        ans = min(ans, dp[n][i]);
    }
    cout << ans;
    
    return 0;
}
