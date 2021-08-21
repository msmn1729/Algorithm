#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/20010 악덕 영주 혜유

int visited[101010];
int parent[101010];
int n, k;
vector<pll> graph[101010]; // MST 인접리스트

struct info {
    ll cost;
    int st, ed;
};

ll dfs(ll cur) {
    visited[cur] = 1;
    ll ret = 0;
    for(auto it : graph[cur]) {
        ll nxt = it.first;
        ll nxt_cost = it.second;
        if(visited[nxt]) continue;
        ret = max(ret, dfs(nxt) + nxt_cost);
    }
    return ret;
}

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

bool cmp(info a, info b) {
    return a.cost < b.cost;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    vector<info> v;
    cin >> n >> k;
    for(int i=0; i<n; i++) parent[i] = -1;
    for(int i=0; i<k; i++) {
        int st, ed, cost;
        cin >> st >> ed >> cost;
        v.push_back({cost, st, ed});
    }
    
    sort(v.begin(), v.end(), cmp);
    ll min_ans = 0;
    for(auto &[cost, st, ed] : v) {
        if(!merge(st, ed)) continue;
        min_ans += cost;
        // MST 인접리스트 생성
        graph[st].push_back({ed, cost});
        graph[ed].push_back({st, cost});
    }
    cout << min_ans << '\n';
    
    ll max_ans = 0;
    for(int i=1; i<=n; i++) {
        max_ans = max(max_ans, dfs(i));
        memset(visited, 0, sizeof(visited));
    }
    cout << max_ans;
    
    return 0;
}
