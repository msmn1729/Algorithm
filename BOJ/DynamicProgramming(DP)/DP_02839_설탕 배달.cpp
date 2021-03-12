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

//https://www.acmicpc.net/problem/2839 설탕 배달

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int dp[5001] = {};
    fill(dp, dp+5001, INF);
    dp[3] = dp[5] = 1;
    for(int i=6; i<=n; i++) {
        dp[i] = min(dp[i-3], dp[i-5]) + 1;
    }
    
    if(dp[n] >= INF) cout << -1;
    else cout << dp[n];
    
    return 0;
}
