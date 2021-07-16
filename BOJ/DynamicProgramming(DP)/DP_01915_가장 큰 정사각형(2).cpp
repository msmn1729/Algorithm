#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
// https://www.acmicpc.net/problem/1915 가장 큰 정사각형

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    int dp[1001][1001] = {};
    for(int i=1; i<=n; i++) {
        string s;
        cin >> s;
        for(int j=1; j<=m; j++) dp[i][j] = s[j-1] - '0';
    }
    
    int ans = dp[0][0];
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(dp[i][j] == 0) continue;
            dp[i][j] += min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
            ans = max(ans, dp[i][j] * dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}
