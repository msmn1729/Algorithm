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

//https://www.acmicpc.net/problem/2579 계단 오르기

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int ar[301] = {};
    int dp[301][3] = {};
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> ar[i];
    if(n == 1) {
        cout << ar[1];
        return 0;
    }
    dp[1][1] = ar[1];
    dp[2][1] = ar[2];
    dp[2][2] = ar[1] + ar[2];
    for(int i=3; i<=n; i++) {
        dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + ar[i];
        dp[i][2] = dp[i-1][1] + ar[i];
    }
    cout << max(dp[n][1], dp[n][2]);
    
    return 0;
}
