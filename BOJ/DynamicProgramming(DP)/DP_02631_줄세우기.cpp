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
    
    int n;
    cin >> n;
    vector<int> v(n+1);
    vector<int> dp(n+1); // dp[a]: a번 째 아이의 LIS
    
    for(int i=1; i<=n; i++) cin >> v[i];
    
    int mx = 0, ans = 0;
    for(int i=1; i<=n; i++) {
        dp[i] = 1;
        for(int j=1; j<i; j++) {
            if(v[i] < v[j]) continue;
            dp[i] = max(dp[i], dp[j] + 1);
        }
        mx = max(mx, dp[i]);
    }
    ans = n - mx;
    cout << ans;
    
    return 0;
}
