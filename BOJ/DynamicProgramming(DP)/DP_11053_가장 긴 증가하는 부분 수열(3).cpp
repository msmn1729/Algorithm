#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    int ar[100001] = {}, dp[100001] = {};
    cin >> n;
    int ans = 1;
    
    for(int i=1; i<=n; i++) {
        cin >> ar[i];
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

