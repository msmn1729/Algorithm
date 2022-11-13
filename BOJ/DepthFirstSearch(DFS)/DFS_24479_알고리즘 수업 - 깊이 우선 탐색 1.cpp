#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

priority_queue<int, vector<int>, greater<>> adj[100001];
int visited[100001];
int visitOrder[100001];
int cnt;

void dfs(int cur) {
    visited[cur] = 1;
    visitOrder[cur] = ++cnt;
    
    while(adj[cur].size()) {
        int nxt = adj[cur].top();
        if(visited[nxt]) {
            adj[cur].pop();
            continue;
        }
        dfs(nxt);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, r;
    cin >> n >> m >> r;
    
    for(int i=0; i<m; i++) {
        int st, ed;
        cin >> st >> ed;
        adj[st].push(ed);
        adj[ed].push(st);
    }
    
    dfs(r);
    
    for(int i=1; i<=n; i++) {
        cout << visitOrder[i] << '\n';
    }
    
    return 0;
}
