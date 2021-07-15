#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
// https://www.acmicpc.net/problem/2579 계단 오르기

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    int ar[301] = {}, dp[301][3] = {}; // dp[a][b] : 연속으로 b개 밟아서 a번째 계단일 때 최댓값
    cin >> n;
    for(int i=1; i<=n; i++) cin >> ar[i];
    dp[1][1] = ar[1];
    for(int i=2; i<=n; i++) {
        dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + ar[i];
        dp[i][2] = dp[i-1][1] + ar[i];
    }
    cout << max(dp[n][1], dp[n][2]);
    
    return 0;
}
