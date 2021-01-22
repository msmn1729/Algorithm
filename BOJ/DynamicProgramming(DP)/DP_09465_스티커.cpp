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

using namespace std;

//https://www.acmicpc.net/problem/9465 스티커

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        int ar[2][100001] = {};
        int dp[2][100001] = {};
        for(int i=0; i<2; i++) {
            for(int j=0; j<n; j++) cin >> ar[i][j];
        }
        dp[0][0] = ar[0][0];
        dp[1][0] = ar[1][0];
        dp[0][1] = ar[1][0] + ar[0][1];
        dp[1][1] = ar[0][0] + ar[1][1];
    
        for(int j=2; j<n; j++) {
            dp[0][j] = max(dp[1][j-1], dp[1][j-2]) + ar[0][j];
            dp[1][j] = max(dp[0][j-1], dp[0][j-2]) + ar[1][j];
        }
        cout << max(dp[0][n-1], dp[1][n-1]) << '\n';
    }
    
    return 0;
}
