#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/1197 최소 스패닝 트리

struct info {
    ll st, ed, cost;
};

ll v, e;
ll parent[10001];

bool operator<(info a, info b) {
    return a.cost > b.cost;
}

ll find(ll n) {
    if(parent[n] == n) return n;
    return parent[n] = find(parent[n]); // 이 부분 다시 찾아볼 것
}

void merge(ll a, ll b) {
    a = find(a);
    b = find(b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    // 크루스칼: 가중치 순으로 정렬한 후 사이클이 안생기도록 순서대로 트리 생성
    // 1. 가중치를 오름차순으로 정렬
    // 2. 사이클을 형성하는 간선을 제외하며 MST 생성
    
    priority_queue<info> pq;
    cin >> v >> e;
    for(int i=0; i<e; i++) {
        ll st, ed, cost;
        cin >> st >> ed >> cost;
        pq.push({st, ed, cost});
    }
    
    // 사이클 확인 -> 유니온 파인드
    for(int i=1; i<=v; i++) parent[i] = i;
    
    ll ans = 0;
    while(!pq.empty()) {
        ll st = pq.top().st;
        ll ed = pq.top().ed;
        ll cost = pq.top().cost; pq.pop();
        
        if(find(st) == find(ed)) continue;
        merge(st, ed);
        ans += cost;
    }
    cout << ans;
    
    return 0;
}
