#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/1185 유럽여행

struct info {
    int st, ed, cost;
};

int n, m, k;
int parent[10101];
int ar_cost[10101];
vector<info> edges;

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

bool cmp(info a, info b) {
    return a.cost < b.cost;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m, mn = 2e9;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> ar_cost[i];
        mn = min(mn, ar_cost[i]);
    }
    memset(parent, -1, sizeof(parent));
    
    for(int i=0; i<m; i++) {
        int st, ed, cost;
        cin >> st >> ed >> cost;
        edges.push_back({st, ed, cost * 2 + ar_cost[st] + ar_cost[ed]});
    }
    sort(edges.begin(), edges.end(), cmp);
    
    int ans = mn; // 시작하는 나라를 한번 더 방문하므로 더해줌
    for(int i=0; i<edges.size(); i++) {
        int st = edges[i].st;
        int ed = edges[i].ed;
        int cost = edges[i].cost;
        
        if(!merge(st, ed)) continue;
        ans += cost;
    }
    cout << ans;
    
    return 0;
}
