#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

const int mod = 1000000007;

ll go(ll p, ll n) {
    if(n == 1) return p;
    if(n%2 == 0) return go(p, n/2) % mod * go(p, n/2) % mod;
    else return go(p, n/2) % mod * go(p, n/2) % mod * p % mod;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    ll k, p, n;
    cin >> k >> p >> n;
    
    ll ans = (k * go(p, n * 10)) % mod;
    cout << ans;
    
    return 0;
}
