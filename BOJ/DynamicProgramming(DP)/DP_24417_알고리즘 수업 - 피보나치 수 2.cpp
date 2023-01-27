#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

const int MOD = INF + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll n;
    cin >> n;
    ll a = 1, b = 1, sum = 0;
    
    for(int i=3; i<=n; i++) {
        sum = a + b;
        sum %= MOD;
        a = b;
        b = sum;
    }
    cout << sum << " " << n-2;
    
    return 0;
}
