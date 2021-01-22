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

//https://www.acmicpc.net/problem/1149 RGB거리

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, i, j;
    cin >> n;
    int dp[1001][4] = {};

    for(i=1; i<=n; i++) for(j=1; j<=3; j++) cin >> dp[i][j];

    for(i=1; i<=n; i++) {
        dp[i][1] += min(dp[i-1][2], dp[i-1][3]);
        dp[i][2] += min(dp[i-1][3], dp[i-1][1]);
        dp[i][3] += min(dp[i-1][1], dp[i-1][2]);
    }
    cout << min(min(dp[n][1], dp[n][2]), dp[n][3]);

    return 0;
}
