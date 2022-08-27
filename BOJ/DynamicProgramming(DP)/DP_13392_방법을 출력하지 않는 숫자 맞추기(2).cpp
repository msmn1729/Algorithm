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

    for(int i=1; i<=n; i++) from[i] = s1[i-1] - '0';
    for(int i=1; i<=n; i++) to[i] = s2[i-1] - '0';
    
    // dp 초기세팅
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=9; j++) {
            dp[i][j] = 1e9;
        }
    }
    for(int i=0; i<=9; i++) dp[0][i] = i;
    
    // i는 위치
    for(int i=1; i<=n; i++) {
        // j는 이전의 모든 왼쪽 회전횟수(0~9)
        for(int j=0; j<=9; j++) {
            int curNum = (from[i] + j) % 10;
            int curLeftCnt = (to[i] - curNum + 10) % 10;
            int curRightCnt = 10 - curLeftCnt;
            
            // 이번에 오른쪽 회전하는 경우
            dp[i][j] = min(dp[i][j], dp[i-1][j] + curRightCnt);
            // 이번에 왼쪽 회전하는 경우
            dp[i][(j + curLeftCnt) % 10] = min(dp[i][(j + curLeftCnt) % 10], dp[i-1][j] + curLeftCnt);
        }
    }
    
    // 출력
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
