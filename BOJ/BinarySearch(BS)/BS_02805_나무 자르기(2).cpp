#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
// https://www.acmicpc.net/problem/2805 나무 자르기

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    
    ll st = 0, ed = *max_element(v.begin(), v.end());
    ll ans = 0;
    
    while(st <= ed) {
        ll mid = (st + ed) / 2;
        ll sum = 0;
        for(ll it : v) {
            if(it - mid <= 0) continue;
            sum += (it - mid);
        }
        if(sum >= m) {
            ans = max(ans, mid);
            st = mid + 1;
        }
        else if(sum < m) ed = mid - 1;
    }
    cout << ans;
    
    return 0;
}
