#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/1766 문제집

int n, m;
int indegree[32010] = {};
vector<int> graph[32010];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    
    priority_queue<int> pq;
    for(int i=1; i<=n; i++) {
        if(indegree[i]) continue;
        pq.push(-i);
    }
    
    while(pq.size()) {
        int cur = -pq.top(); pq.pop();
        cout << cur << ' ';
        for(int i=0; i<graph[cur].size(); i++) {
            int nxt = graph[cur][i];
            indegree[nxt]--;
            if(indegree[nxt] == 0) pq.push(-nxt);
        }
    }
    
    return 0;
}
