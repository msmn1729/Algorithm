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

//https://www.acmicpc.net/problem/17404 RGB거리 2

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    int ar[1001][4] = {};
    
    for(int i=1; i<=n; i++) for(int j=1; j<=3; j++) cin >> ar[i][j];
    
    int mn = INF;
    for(int k=1; k<=3; k++) {
        int dp[1001][4] = {};
        for(int i=1; i<=3; i++) {
            if(i == k) dp[1][i] = ar[1][i];
            else dp[1][i] = INF;
        }
        for(int i=2; i<=n; i++) {
            dp[i][1] = min(dp[i-1][2], dp[i-1][3]) + ar[i][1];
            dp[i][2] = min(dp[i-1][3], dp[i-1][1]) + ar[i][2];
            dp[i][3] = min(dp[i-1][1], dp[i-1][2]) + ar[i][3];
        }
        for(int i=1; i<=3; i++) {
            if(i == k) continue;
            mn = min(mn, dp[n][i]);
        }
    }
    cout << mn;
    
    return 0;
}
