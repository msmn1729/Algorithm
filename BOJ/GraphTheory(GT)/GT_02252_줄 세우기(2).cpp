#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/2252 줄 세우기

int n, m;
int indegree[101010] = {};
vector<int> graph[101010];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    
    queue<int> q;
    for(int i=1; i<=n; i++) {
        if(indegree[i] == 0) q.push(i);
    }
    
    vector<int> ans;
    while(q.size()) {
        int cur = q.front(); q.pop();
        ans.push_back(cur);
        for(int i=0; i<graph[cur].size(); i++) {
            int nxt = graph[cur][i];
            indegree[nxt]--;
            if(indegree[nxt] == 0) q.push(nxt);
        }
    }
    
    for(int a : ans) cout << a << ' ';
    
    return 0;
}
