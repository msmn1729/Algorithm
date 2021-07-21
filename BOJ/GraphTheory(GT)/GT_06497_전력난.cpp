#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/6497 전력난

struct info {
    int st, ed, cost;
};

int parent[202020];

bool cmp(info a, info b) {
    return a.cost < b.cost;
}

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
    
    while(1) {
        int m, n, ans = 0;
        vector<info> v;
        cin >> m >> n;
        if(!m && !n) break;
        
        for(int i=0; i<m; i++) parent[i] = i;
        
        for(int i=0; i<n; i++) {
            int st, ed, cost;
            cin >> st >> ed >> cost;
            v.push_back({st, ed, cost});
            ans += cost;
        }
        sort(v.begin(), v.end(), cmp);
        
        for(auto &[st, ed, cost] : v) {
            if(merge(st, ed)) ans -= cost;
        }
        cout << ans << '\n';
    }
    
    return 0;
}
