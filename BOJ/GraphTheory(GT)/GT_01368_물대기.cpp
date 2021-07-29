#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/1368 물대기

int parent[303];

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
    vector<tuple<int, int, int>> v;
    cin >> n;
    
    for(int i=1; i<=n; i++) {
        int cost;
        cin >> cost;
        parent[i] = i;
        v.push_back({cost, i, 0});
    }
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int cost;
            cin >> cost;
            if(i >= j) continue;
            v.push_back({cost, i, j});
        }
    }
    sort(v.begin(), v.end());
    
    int ans = 0;
    for(auto &[cost, st, ed] : v) {
        if(!merge(st, ed)) continue;
        ans += cost;
    }
    cout << ans;
    
    return 0;
}
