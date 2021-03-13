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

//https://www.acmicpc.net/problem/1149 RGB거리

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<vector<int> > dp(2, vector<int>(3));
    int n;
    cin >> n;
    while(n--) {
        int a, b, c;
        cin >> a >> b >> c;
        
        dp[1][0] = min(dp[0][1], dp[0][2]) + a;
        dp[1][1] = min(dp[0][2], dp[0][0]) + b;
        dp[1][2] = min(dp[0][0], dp[0][1]) + c;
        dp[0] = dp[1];
    }
    sort(dp[0].begin(), dp[0].end());
    cout << dp[0][0];
    
    return 0;
}
