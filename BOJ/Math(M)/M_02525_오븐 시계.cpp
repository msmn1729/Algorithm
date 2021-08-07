#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/2525 오븐 시계

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   
    int a, b, c;
    cin >> a >> b >> c;
    b += a * 60 + c;
    
    int h, m;
    h = (b / 60) % 24;
    m = b % 60;
    cout << h << ' ' << m;
    
    return 0;
}
