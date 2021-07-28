#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/1939 중량제한

int parent[101010];

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
    
    int n, m, depart, arrival;
    cin >> n >> m;
    vector<tuple<int, int, int>> edge(m);
    
    for(int i=1; i<=n; i++) parent[i] = i;
    for(auto &[cost, st, ed] : edge) cin >> st >> ed >> cost;
    cin >> depart >> arrival;
    sort(edge.begin(), edge.end(), greater<>());
    
    for(auto &[cost, st, ed] : edge) {
        if(!merge(st, ed)) continue;
        if(find(depart) == find(arrival)) {
            cout << cost;
            return 0;
        }
    }
    cout << 0;
    return 0;
}
