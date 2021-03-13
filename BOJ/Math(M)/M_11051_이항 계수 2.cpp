#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <iomanip>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/11051 이항 계수 2

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    int dp[1001][1001] = {};
    for(int i=0; i<=n; i++) dp[i][0] = 1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            dp[i][j] %= 10007;
        }
    }
    cout << dp[n][k];
    
    return 0;
}
