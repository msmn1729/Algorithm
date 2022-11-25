#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll a, b;
    cin >> a >> b;
    ll ans = (a+b) * (a-b);
    cout << ans;
    
    return 0;
}
