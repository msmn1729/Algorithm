#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/1774 우주신과의 교감

struct info {
    int st;
    int ed;
    double dist;
};

int parent[1001];

bool cmp(info a, info b) {
    return a.dist < b.dist;
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
    
    int n, m;
    cin >> n >> m;
    
    vector<pll> v;
    // 크루스칼
    for(int i=1; i<=n; i++) parent[i] = i;
    for(int i=0; i<n; i++) {
        ll x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    
    // 이미 연결된 두 점
    for(int i=0; i<m; i++) {
        int st, ed;
        cin >> st >> ed;
        merge(--st, --ed);
    }

    vector<info> graph;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            ll f = v[i].first - v[j].first;
            ll s = v[i].second - v[j].second;
            graph.push_back({i, j, sqrt(f*f + s*s)});
        }
    }
    sort(graph.begin(), graph.end(), cmp);
    
    double ans = 0;
    for(auto &[st, ed, dist] : graph) {
        if(merge(st, ed)) ans += dist;
    }
    // 출력방식은 둘 다 가능
//    cout << setprecision(2) << fixed << ans;
    printf("%.2lf", ans);
   
    return 0;
}
