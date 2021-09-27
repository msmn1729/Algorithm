#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    ll k, p, n;
    cin >> k >> p >> n;
    
    ll ans = k;
    for(int i=0; i<n; i++) {
        ans *= p;
        ans %= 1000000007;
    }
    cout << ans;
    
    return 0;
}
