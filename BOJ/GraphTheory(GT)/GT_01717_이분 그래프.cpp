#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/1707 이분 그래프

vector<int> graph[20202];
int visited[20202];

void dfs(int cur, int group) {
    visited[cur] = group; // 방문순으로 -1, 1로 그룹분할
    for(int nxt : graph[cur]) {
        if(visited[nxt]) continue;
        dfs(nxt, -group);
    }
}

// 이분 그래프 체크
bool isBipartiteGraph(int v) {
    for(int cur=1; cur<=v; cur++) {
        for(int nxt : graph[cur]) {
            if(visited[cur] == visited[nxt]) return 0;
        }
    }
    return 1;
}

void init(int v) {
    for(int i=1; i<=v; i++) {
        graph[i].clear();
        visited[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t, v, e;
    cin >> t;
    while(t--) {
        cin >> v >> e;
        init(v);
        
        for(int i=0; i<e; i++) {
            int st, ed;
            cin >> st >> ed;
            graph[st].push_back(ed);
            graph[ed].push_back(st);
        }
        
        // 방문하지 않은 정점들을 탐색
        for(int i=1; i<=v; i++) {
            if(visited[i]) continue;
            dfs(i, 1);
        }
        
        if(isBipartiteGraph(v)) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}
