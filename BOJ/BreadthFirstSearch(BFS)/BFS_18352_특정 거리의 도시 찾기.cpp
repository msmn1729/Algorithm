#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int n, m, k, x;
vector<int> adj[300001];
int visited[300001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k >> x;
    
    for(int i=0; i<m; i++) {
        int st, ed;
        cin >> st >> ed;
        adj[st].push_back(ed);
    }
    
    queue<pair<int, int> > q;
    q.push({x, 0});
    visited[x] = 1;
    
    vector<int> ans;
    
    while(q.size()) {
        int cur = q.front().first;
        int depth = q.front().second;
        q.pop();
        if(depth == k) {
            ans.push_back(cur);
        }
        
        for(int nxt : adj[cur]) {
            if(visited[nxt]) continue;
            visited[nxt] = 1;
            q.push({nxt, depth + 1});
        }
    }
    
    if(ans.empty()) cout << -1;
    else {
        sort(ans.begin(), ans.end());
        for(int it : ans) cout << it << '\n';
    }
    
    return 0;
}
