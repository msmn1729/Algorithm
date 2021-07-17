#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/1922 네트워크 연결

struct info {
    int st, ed, cost;
};

int parent[100001];

bool operator<(info a, info b) {
    return a.cost < b.cost;
}

int find(int a) {
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    parent[a] = b;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    // 크루스칼 O(E(logE))
    int n, m;
    vector<info> graph;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int st, ed, cost;
        cin >> st >> ed >> cost;
        graph.push_back({st, ed, cost});
    }
    sort(graph.begin(), graph.end());
    for(int i=1; i<=n; i++) parent[i] = i;
    
    int ans = 0;
    for(int i=0; i<m; i++) {
        int st = graph[i].st;
        int ed = graph[i].ed;
        int cost = graph[i].cost;
        if(find(st) == find(ed)) continue;
        merge(st, ed);
        ans += cost;
    }
    cout << ans;

    return 0;
}
