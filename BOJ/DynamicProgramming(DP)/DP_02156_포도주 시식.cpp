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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    int dp[10001][3] = {};
    int ar[10001] = {};
    cin >> n;
    
    for(int i=1; i<=n; i++) {
        cin >> ar[i];
    }

    int ans = 0;
    ans = dp[1][1] = ar[1];
    for(int i=2; i<=n; i++) {
        dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + ar[i];
        dp[i][2] = dp[i-1][1] + ar[i];
        dp[i][1] = max(dp[i][1], dp[i-1][1]);
        dp[i][2] = max(dp[i][2], dp[i-1][2]);
        ans = max(ans, max(dp[i][1], dp[i][2]));
    }
    cout << ans;
    
    return 0;
}
