#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/21921 블로그

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    int sum = 0;
    for(int i=0; i<n; i++) {
        cin >> v[i];
        if(i < x) sum += v[i];
    }
    
    int mx = sum;
    int cnt = 1;
    
    for(int i=0; i<n - x; i++) {
        sum -= v[i];
        sum += v[i + x];
        if(mx < sum) {
            mx = sum;
            cnt = 1;
        }
        else if(mx == sum) cnt++;
    }
    
    if(mx == 0) cout << "SAD";
    else {
        cout << mx << '\n';
        cout << cnt;
    }
    
    return 0;
}
