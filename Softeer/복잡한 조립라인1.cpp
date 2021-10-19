#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k, n;
    cin >> k >> n;
    int dp[105][105] = {};
    int time[105][105] = {};
    // mvtime[k][n][a] : (k라인, n번)작업장에서 (a라인, n+1번)작업장으로 옮길 때의 이동시간
    int mvtime[105][105][105] = {};
    
    
    for(int col=1; col<=n; col++) {
        for(int i=1; i<=k; i++) {
            cin >> time[i][col];
        }
        if(col == n) break;
        for(int i=1; i<=k; i++) {
            for(int j=1; j<=k; j++) {
                if(i != j) cin >> mvtime[i][col][j];
            }
        }
    }
    
    // 1번 열 미리 채우기
    for(int i=1; i<=k; i++) {
        dp[i][1] = time[i][1];
    }
    for(int j=2; j<=n; j++) {
        for(int i=1; i<=k; i++) {
            int mn = dp[i][j-1]; // 일자로 이동하는 경우
            for(int a=1; a<=k; a++) {
                if(a == i) continue; // 행이 같으면 패스
                mn = min(mn, dp[a][j-1] + mvtime[a][j-1][i]);
            }
            dp[i][j] = mn + time[i][j];
        }
    }
    int ans = 2e9;
    for(int i=1; i<=k; i++) ans = min(ans, dp[i][n]);
    cout << ans;
    
    return 0;
}
