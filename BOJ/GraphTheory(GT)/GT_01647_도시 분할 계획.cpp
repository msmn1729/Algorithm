#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/1647 도시 분할 계획

struct info {
    int st, ed, cost;
};

int parent[101010];

bool operator<(info a, info b) {
    return a.cost < b.cost;
}

int find(int a) {
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    parent[a] = b;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    // 크루스칼
    vector<info> v;
    int n, m, answer = 0;
    int st, ed, cost;
    cin >> n >> m;
    
    for(int i=1; i<=n; i++) parent[i] = i;
    
    for(int i=0; i<m; i++) {
        cin >> st >> ed >> cost;
        v.push_back({st, ed, cost});
    }
    
    // 정렬 or pq
    sort(v.begin(), v.end());
    
    int mx = 0;
    for(int i=0; i<m; i++) {
        st = v[i].st;
        ed = v[i].ed;
        cost = v[i].cost;
        
        if(find(st) == find(ed)) continue;
        merge(st, ed);
        answer += cost;
        mx = max(mx, cost);
    }
    cout << answer - mx;
    
    return 0;
}
