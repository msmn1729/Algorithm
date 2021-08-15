#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/11049 행렬 곱셈 순서

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int dp[501][501] = {}; // dp[a][b] : a번째 행렬부터 b번째 행렬까지 곱했을 때 최소 연산의 수
    int row[501] = {}, col[501] = {};
    int n, r, c;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> r >> c;
        row[i] = r;
        col[i] = c;
    }
    
    for(int i=n-1; i>=1; i--) {
        for(int j=i+1; j<=n; j++) {
            dp[i][j] = 2e9;
            for(int k=i; k<=j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + row[i] * col[k] * col[j]);
            }
        }
    }
    cout << dp[1][n];
    
    return 0;
}
