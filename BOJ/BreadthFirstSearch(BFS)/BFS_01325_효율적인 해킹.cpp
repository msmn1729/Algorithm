#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/1325 효율적인 해킹

vector<int> v[10101];
int visited[10101];
int n, m;

int bfs(int start) {
    memset(visited, 0, sizeof(visited));
    int cnt = 1;
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int i=0; i<v[cur].size(); i++) {
            int nxt = v[cur][i];
            if(visited[nxt]) continue;
            visited[nxt] = 1;
            q.push(nxt);
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int st, ed;
        cin >> st >> ed;
        v[ed].push_back(st);
    }
    
    int cnts[10101] = {};
    int mx = 0;
    for(int i=1; i<=n; i++) {
        int cnt = bfs(i);
        mx = max(mx, cnt);
        cnts[i] = cnt;
    }
    
    for(int i=1; i<=n; i++) {
        if(mx == cnts[i]) cout << i << ' ';
    }
    
    return 0;
}
