#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll n;
    string ans = "";
    cin >> n;
    
    while(n) {
        ans = to_string(n%2) + ans;
        n /= 2;
    }
    cout << ans;
    
    return 0;
}
