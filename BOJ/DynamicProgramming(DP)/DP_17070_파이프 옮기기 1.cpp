#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <map>
#include <iomanip>
#include <list>
#include <stack>
#include <cstring>
#include <cmath>
#include <set>
#include <unordered_map>
#include <bitset>
#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/17070 파이프 옮기기 1

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int board[20][20] = {};
    int dp[4][20][20] = {};
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> board[i][j];
        }
    }
    
    dp[1][1][3] = dp[3][2][3] = 1;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(board[i][j]) {
                dp[1][i][j] = dp[2][i][j] = dp[3][i][j] = 0;
                continue;
            }
            dp[1][i][j] += dp[1][i][j-1] + dp[3][i][j-1];
            dp[2][i][j] += dp[2][i-1][j] + dp[3][i-1][j];
            if(board[i-1][j] || board[i][j-1]) {
                dp[3][i][j] = 0;
                continue;
            }
            dp[3][i][j] += dp[1][i-1][j-1] + dp[2][i-1][j-1] + dp[3][i-1][j-1];
        }
    }
    
    int ans = 0;
    for(int k=1; k<=3; k++) ans += dp[k][n][n];
    cout << ans;
    
    return 0;
}
