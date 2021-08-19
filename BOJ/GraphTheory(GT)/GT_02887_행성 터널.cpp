#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/2887 행성 터널

struct info {
    int idx, x, y, z;
};

int parent[101010];

int find(int a) {
    if(parent[a] == -1) return a;
    return parent[a] = find(parent[a]);
}

bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return false;
    parent[a] = b;
    return true;
}

bool cmp_x(info a, info b) {
    return a.x < b.x;
}

bool cmp_y(info a, info b) {
    return a.y < b.y;
}

bool cmp_z(info a, info b) {
    return a.z < b.z;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    vector<info> pos;
    vector<tuple<ll, int, int>> v;
    cin >> n;
    for(int i=0; i<n; i++) {
        parent[i] = -1;
        int a, b, c;
        cin >> a >> b >> c;
        pos.push_back({i, a, b, c});
    }
    
    sort(pos.begin(), pos.end(), cmp_x);
    for(int i=0; i<n-1; i++) {
        info cur = pos[i];
        info nxt = pos[i+1];
        int dist = (nxt.x - cur.x);
        v.push_back({dist, cur.idx, nxt.idx});
    }
    
    sort(pos.begin(), pos.end(), cmp_y);
    for(int i=0; i<n-1; i++) {
        info cur = pos[i];
        info nxt = pos[i+1];
        int dist = (nxt.y - cur.y);
        v.push_back({dist, cur.idx, nxt.idx});
    }
    
    sort(pos.begin(), pos.end(), cmp_z);
    for(int i=0; i<n-1; i++) {
        info cur = pos[i];
        info nxt = pos[i+1];
        int dist = (nxt.z - cur.z);
        v.push_back({dist, cur.idx, nxt.idx});
    }
    
    sort(v.begin(), v.end());
    ll ans = 0;
    for(auto &[dist, st, ed] : v) {
        if(!merge(st, ed)) continue;
        ans += dist;
    }
    cout << ans;
    
    return 0;
}
