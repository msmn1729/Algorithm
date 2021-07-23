#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/6091 핑크 플로이드

int parent[1030];

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
    
    vector<tuple<int, int, int>> edges;
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            int cost;
            cin >> cost;
            edges.push_back({cost, i, j});
        }
    }
    memset(parent, -1, sizeof(parent));
    sort(edges.begin(), edges.end());
    
    vector<vector<int>> adj(n + 1, vector<int>());
    for(auto &[cost, st, ed] : edges) {
        if(!merge(st, ed)) continue;
        adj[st].push_back(ed);
        adj[ed].push_back(st);
    }
    
    for(int i=1; i<=n; i++) {
        auto &v = adj[i];
        cout << v.size() << ' ';
        sort(v.begin(), v.end());
        for(auto &vertex : v) cout << vertex << ' ';
        cout << '\n';
    }
    
    return 0;
}
