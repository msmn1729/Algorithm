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

//https://www.acmicpc.net/problem/1003 피보나치 함수

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int dp[2][41] = {};
    dp[0][0] = 1;
    dp[1][1] = 1;
    
    for(int i=2; i<=40; i++) {
        dp[0][i] = dp[0][i-1] + dp[0][i-2];
        dp[1][i] = dp[1][i-1] + dp[1][i-2];
    }
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << dp[0][n] << ' ' << dp[1][n] << '\n';
    }
    
    return 0;
}
