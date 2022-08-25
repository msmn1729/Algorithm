#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <cmath>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> adjacency[n+1];
    vector<int> indegree(n+1);
    vector<int> dp(n+1);
    
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adjacency[a].push_back(b);
        indegree[b]++;
    }
    
    queue<int> q;
    for(int i=1; i<=n; i++) {
        dp[i] = 1;
        if(indegree[i]) continue;
        q.push(i);
    }
    
    while(q.size()) {
        int cur = q.front();
        q.pop();
        for(int i=0; i<adjacency[cur].size(); i++) {
            int nxt = adjacency[cur][i];
            indegree[nxt]--;
            dp[nxt] = dp[cur] + 1;
            if(indegree[nxt]) continue;
            q.push(nxt);
        }
    }
    for(int i=1; i<=n; i++) cout << dp[i] << ' ';
    
    return 0;
}
