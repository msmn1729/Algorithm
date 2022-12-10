#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    int dp[101] = {0, 1};
    for(int i=2; i<=100; i++) {
        dp[i] = dp[i-1] + i*i;
    }
    
    while(1) {
        cin >> n;
        if(n == 0) break;
        cout << dp[n] << '\n';
    }
    
    return 0;
}

