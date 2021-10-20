#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
#include <set>
#define ll long long
using namespace std;
const int mod = 1e9+7;

// p^n을 mod로 나눈 나머지를 반환
ll go(ll p, ll n) {
    if(n == 0) return 1;
    if(n%2 == 0) return go(p, n/2) % mod * go(p, n/2) % mod;
    return go(p, n/2) % mod * go(p, n/2) % mod * p % mod;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll p, n;
    cin >> p >> n;
    
    ll ans = 0;
    for(int i=0; i<n; i++) {
        ll a;
        cin >> a;
        ll birus = (a * go(p, n-i-1));
        ans += birus;
        ans %= mod;
    }
    cout << ans;

    return 0;
}
