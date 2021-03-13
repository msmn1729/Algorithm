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

//https://www.acmicpc.net/problem/1932 정수 삼각형

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int> > dp(2, vector<int>(n+1));
    
    for(int i=1; i<=n; i++) {
        vector<int> v(i+1);
        for(int j=1; j<=i; j++) cin >> v[j];
        for(int j=1; j<=i; j++) dp[1][j] = max(dp[0][j], dp[0][j-1]) + v[j];
        dp[0] = dp[1];
    }
    
    sort(dp[0].begin(), dp[0].end());
    cout << dp[0].back();
    
    return 0;
}
