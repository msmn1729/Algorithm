#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/21924 도시 건설

int parent[101010];

int find(int a) {
    if(parent[a] < 0) return a;
    return parent[a] = find(parent[a]);
}

bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return false;
    parent[a] = b;
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m;
    ll ans = 0;
    cin >> n >> m;
    
    vector<tuple<ll, int, int>> v;
    fill(parent, parent+n+1, -1);
    for(int i=0; i<m; i++) {
        int st, ed, cost;
        cin >> st >> ed >> cost;
        ans += cost;
        v.push_back({cost, st, ed});
    }
    sort(v.begin(), v.end());

    for(auto& [cost, st, ed] : v) {
        if(merge(st, ed)) ans -= cost;
    }
    for(int i=2; i<=n; i++) {
        if(merge(1, i)) {
            ans = -1;
            break;
        }
    }
    cout << ans;
    
    return 0;
}
