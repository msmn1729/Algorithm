#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/2458 키 순서

int n, m;
int visited[510];
vector<int> graph[2][510];

int dfs(int reverse, int cur) {
    int ret = 1;
    for(int nxt : graph[reverse][cur]) {
        if(visited[nxt]) continue;
        visited[nxt] = 1;
        ret += dfs(reverse, nxt);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m, ans = 0;
    cin >> n >> m;
    
    for(int i=0, a, b; i<m; i++) {
        cin >> a >> b;
        graph[0][a].push_back(b);
        graph[1][b].push_back(a);
    }
    
    for(int i=1; i<=n; i++) {
        fill(visited, visited+n+1, 0);
        int u = dfs(0, i);
        int v = dfs(1, i);
        if(u + v == n+1) ans++;
    }
    cout << ans;
    
    return 0;
}
