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

    int dp[201][201] = {};
    int n, k;
    cin >> n >> k;
    
    for(int i=1; i<=n; i++) {
        dp[i][1] = 1;
    }
    
    for(int j=1; j<=k; j++) {
        dp[0][j] = 1;
    }
    
    for(int j=1; j<=k; j++) {
        for(int i=1; i<=n; i++) {
            for(int l=0; l<=i; l++) {
                dp[i][j] += dp[l][j-1];
                dp[i][j] %= 1000000000;
            }
        }
    }
    cout << dp[n][k];
    
    return 0;
}
