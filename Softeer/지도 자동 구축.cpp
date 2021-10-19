#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, ans = 2;
    cin >> n;
    
    for(int i=1; i<=n; i++) {
        ans = 2*(ans-1) + 1;
    }
    cout << ans*ans;
    
    return 0;
}
