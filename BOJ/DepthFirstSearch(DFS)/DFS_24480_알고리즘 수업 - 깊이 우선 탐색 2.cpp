#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

vector<int> adj[100001];
int visited[100001];
int answer[100001];
int cnt;

void dfs(int cur) {
    if(visited[cur]) return;
    visited[cur] = 1;
    answer[cur] = ++cnt;
    
    for(auto& nxt : adj[cur]) {
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
        adj[st].push_back(ed);
        adj[ed].push_back(st);
    }
    
    for(int i=1; i<=n; i++) {
        sort(adj[i].begin(), adj[i].end(), greater<>());
    }
    
    dfs(r);
    
    for(int i=1; i<=n; i++) {
        cout << answer[i] << '\n';
    }
    
    return 0;
}
