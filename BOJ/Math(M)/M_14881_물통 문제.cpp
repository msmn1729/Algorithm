#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/14881 물통 문제

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        
        int mx = max(a, b);
        if(mx < c) {
            cout << "NO\n";
            continue;
        }
        
        int tmp = gcd(a, b);
        if(c % tmp == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}
