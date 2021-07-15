#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
// https://www.acmicpc.net/problem/11659 구간 합 구하기 4

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    int dp[100001] = {};
    cin >> n >> m;
    
    for(int i=1; i<=n; i++) {
        cin >> dp[i];
        dp[i] += dp[i-1];
    }
    for(int i=0; i<m; i++) {
        int st, ed;
        cin >> st >> ed;
        cout << dp[ed] - dp[st-1] << '\n';
    }
    
    return 0;
}
