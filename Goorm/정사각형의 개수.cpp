#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll n, ans = 0;
    cin >> n;
    
    // 1 ~ n^2 의 총 합과 같음
    for(ll i=1; i<=n; i++) {
        ans += i*i;
    }
    
    cout << ans;
    
    return 0;
}
