#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    ll fac[21] = {1};
    cin >> n;
    
    if(n == 0) {
        cout << "NO";
        return 0;
    }
    
    for(int i=1; i<=20; i++) {
        fac[i] = fac[i-1] * i;
    }
    
    for(int i=20; i>=0; i--) {
        if(n - fac[i] < 0) continue;
        n -= fac[i];
    }
    
    if(n == 0) cout << "YES";
    else cout << "NO";
    
    return 0;
}
