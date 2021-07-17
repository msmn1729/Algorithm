#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/1197 최소 스패닝 트리

struct info {
    ll ed, cost;
};

ll v, e;
int visited[10001];

bool operator<(info a, info b) {
    return a.cost > b.cost;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    // 프림
    // 1. 시작 단계에서는 시작 정점만이 MST 집합에 포함
    // 2. 인접 정점들 중에 최소 가중치를 가진 간선을 선택해 트리를 추가
    // 3. 위의 과정을 트리가 n-1개의 간선을 가질 때 까지 반복
    
    vector<info> graph[10001];
    priority_queue<info> pq;
    cin >> v >> e;
    for(int i=0; i<e; i++) {
        ll st, ed, cost;
        cin >> st >> ed >> cost;
        graph[st].push_back({ed, cost});
        graph[ed].push_back({st, cost});
    }
    pq.push({1, 0});

    ll ans = 0;
    while(!pq.empty()) {
        ll ed = pq.top().ed;
        ll cost = pq.top().cost; pq.pop();
        if(visited[ed]) continue;
        visited[ed] = 1;
        ans += cost;
        
        for(int i=0; i<graph[ed].size(); i++) {
            pq.push(graph[ed][i]);
        }
    }
    cout << ans;
    
    return 0;
}
