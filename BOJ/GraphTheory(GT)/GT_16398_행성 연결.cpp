#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/16398 행성 연결

int parent[1010];

int find(int a) {
    if(parent[a] == a) return a;
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
    
    int n;
    cin >> n;
    vector<tuple<ll, int, int>> graph;
    for(int i=1; i<=n; i++) parent[i] = i;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            ll cost;
            cin >> cost;
            if(j <= i) continue;
            graph.emplace_back(cost, i, j);
        }
    }
    sort(graph.begin(), graph.end());
    
    ll ans = 0;
    for(auto &[cost, st, ed] : graph) {
        if(merge(st, ed)) ans += cost;
    }
    cout << ans;
    
    return 0;
}
