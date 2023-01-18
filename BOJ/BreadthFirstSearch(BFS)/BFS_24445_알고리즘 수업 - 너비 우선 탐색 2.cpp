#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, r;
    cin >> n >> m >> r;
    vector<int> adj[100001] = {};
    vector<int> ans(n + 1);
    int visited[100001] = {};
    
    for(int i=0; i<m; i++) {
        int st, ed;
        cin >> st >> ed;
        adj[st].push_back(ed);
        adj[ed].push_back(st);
    }
    
    for(int i=1; i<=n; i++) {
        sort(adj[i].begin(), adj[i].end(), greater<>());
    }
    
    queue<int> q;
    int cnt = 1;
    q.push(r);
    visited[r] = 1;
    
    while(q.size()) {
        int cur = q.front();
        ans[cur] = cnt++;
        q.pop();
        
        for(int nxt : adj[cur]) {
            if(visited[nxt]) continue;
            visited[nxt] = 1;
            q.push(nxt);
        }
    }
    
    for(int i=1; i<=n; i++) {
        cout << ans[i] << '\n';
    }
    
    return 0;
}
