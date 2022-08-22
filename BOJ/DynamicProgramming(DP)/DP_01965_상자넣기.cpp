#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <cmath>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ar[1001] = {}, dp[1001] = {};
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++) {
        cin >> ar[i];
    }
    
    int ans = 1;
    for(int i=1; i<=n; i++) {
        dp[i] = 1;
        for(int j=1; j<i; j++) {
            if(ar[i] <= ar[j]) continue;
            dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
    
    return 0;
}
