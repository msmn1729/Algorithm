#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
#include <set>
#define ll long long
using namespace std;
const int mod = 1e9+7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll p, n;
    cin >> p >> n;
    
    ll ans = 0;
    for(int i=0; i<n; i++) {
        ll a;
        cin >> a;
        ans = (ans * p) + a;
        ans %= mod;
    }
    cout << ans;

    return 0;
}
