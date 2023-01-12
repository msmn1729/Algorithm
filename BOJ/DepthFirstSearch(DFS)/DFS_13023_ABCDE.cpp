#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int n, m, ans;
vector<int> adj[2001];
vector<int> vis(2001);

void dfs(int depth, int cur) {
    if(vis[cur]) return;
    vis[cur] = 1;
    if(depth == 4) {
        ans = 1;
        return;
    }
    
    for(int nxt : adj[cur]) {
        dfs(depth + 1, nxt);
    }
    vis[cur] = 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    
    for(int i=0; i<m; i++) {
        int st, ed;
        cin >> st >> ed;
        adj[st].push_back(ed);
        adj[ed].push_back(st);
    }
    
    for(int i=0; i<n; i++) {
        vis = vector<int>(2001);
        dfs(0, i);
        if(ans) break;
    }
    cout << ans;
    
    return 0;
}
