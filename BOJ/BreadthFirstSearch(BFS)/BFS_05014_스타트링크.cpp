#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int f, st, ed, u, d;
    cin >> f >> st >> ed >> u >> d;
    vector<int> dist(f+1, -1);
    queue<int> q;
    int dx[2] = {u, -d};
    
    q.push(st);
    dist[st] = 0;
    
    while(q.size()) {
        int cur = q.front();
        q.pop();
        
        for(int dir=0; dir<2; dir++) {
            int nxt = cur + dx[dir];
            if(nxt<1 || nxt>f) continue;
            if(dist[nxt] != -1) continue;
            q.push(nxt);
            dist[nxt] = dist[cur]+1;
        }
    }
    
    if(dist[ed] != -1) cout << dist[ed];
    else cout << "use the stairs";
    
    return 0;
}
