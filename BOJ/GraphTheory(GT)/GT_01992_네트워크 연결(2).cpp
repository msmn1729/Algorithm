#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/1922 네트워크 연결

struct info {
    int ed, cost;
};

int visited[100001];

bool operator<(info a, info b) {
    return a.cost > b.cost;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    // 프림 O(E(logV))
    int n, m;
    vector<info> graph[10001];
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int st, ed, cost;
        cin >> st >> ed >> cost;
        graph[st].push_back({ed, cost});
        graph[ed].push_back({st, cost});
    }
    
    priority_queue<info> pq;
    int ans = 0;
    // 처음 정점 넣기
    pq.push({1, 0});
    
    while(pq.size()) {
        int ed = pq.top().ed;
        int cost = pq.top().cost; pq.pop();
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
