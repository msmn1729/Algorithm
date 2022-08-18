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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    int ar[1001][1001] = {}, dp[1001][1001] = {};
    
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> ar[i][j];
        }
    }
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            dp[i][j] = max(dp[i][j-1], max(dp[i-1][j], dp[i-1][j-1])) + ar[i][j];
        }
    }
    cout << dp[n][m];
    
    return 0;
}
