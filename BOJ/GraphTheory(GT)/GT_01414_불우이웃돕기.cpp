#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/1414 불우이웃돕기

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
    
    int n, ans = 0;
    cin >> n;
    vector<tuple<int, int, int>> edges;
    
    for(int i=0; i<n; i++) parent[i] = i;
    
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<n; j++) {
            char c = s[j];
            if(c == '0') continue;
            int cost = 0;
            if('a' <= c && c <= 'z') cost = c - 'a' + 1;
            else if('A' <= c && c <= 'Z') cost = c - 'A' + 27;
            edges.push_back({cost, i, j});
            ans += cost;
        }
    }
    sort(edges.begin(), edges.end());
    
    int cnt = 0;
    for(auto &[cost, st, ed] : edges) {
        if(!merge(st, ed)) continue;
        ans -= cost;
        cnt++;
    }
    if(cnt < n-1) cout << -1;
    else cout << ans;
    
    return 0;
} 
