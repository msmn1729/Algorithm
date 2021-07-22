#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/13905 세부

vector<pii> adj[101010];
int n, m, depart, arrival;

int bfs(int mid) {
    queue<pii> q;
    int visit[101010] = {};
    q.push({depart, 0});
    visit[depart] = 1;
    
    while(q.size()) {
        int cur = q.front().first; q.pop();
        
        for(auto &it : adj[cur]) {
            int nxt = it.first;
            int nxt_cost = it.second;
            if(visit[nxt]) continue;
            if(mid > nxt_cost) continue;
            if(nxt == arrival) return 1; // 도착
            
            visit[nxt] = 1;
            q.push({nxt, nxt_cost});
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    cin >> depart >> arrival;
    
    int mx = 0;
    for(int i=0; i<m; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        mx = max(mx, c);
        adj[s].push_back({e, c});
        adj[e].push_back({s, c});
    }
    
    int low = 0, high = mx;
    int ans = 0;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(bfs(mid)) {
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    cout << ans;
    
    return 0;
}
