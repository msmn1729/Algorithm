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
    int dp[10001] = {};
    int ar[10001] = {};
    cin >> n;
    
    for(int i=1; i<=n; i++) {
        cin >> ar[i];
    }

    dp[1] = ar[1];
    dp[2] = ar[1] + ar[2];
    for(int i=3; i<=n; i++) {
        dp[i] = dp[i-2] + ar[i];
        dp[i] = max(dp[i], dp[i-3] + ar[i-1] + ar[i]);
        dp[i] = max(dp[i], dp[i-1]);
    }
    cout << dp[n];
    
    return 0;
}
