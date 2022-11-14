#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> adj[1001];
    vector<int> dist(n+1, -1);
    
    for(int i=0; i<m; i++) {
        int st, ed;
        cin >> st >> ed;
        adj[st].push_back(ed);
        adj[ed].push_back(st);
    }
    
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    
    int cnt = 0;
    while(q.size()) {
        int cur = q.front();
        q.pop();
        
        for(int nxt : adj[cur]) {
            if(dist[nxt] >= 0) continue;
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
        cnt++;
    }
    
    if(1 <= dist[n] && dist[n] <= k) cout << "YES";
    else cout << "NO";
    
    return 0;
}
