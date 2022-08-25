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
    vector<int> graph[n+1];
    vector<int> indegree(n+1);
    
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    
    queue<int> q;
    for(int i=1; i<=n; i++) {
        if(indegree[i]) continue;
        q.push(i);
    }
    
    while(q.size()) {
        int cur = q.front();
        q.pop();
        
        cout << cur << ' ';
        for(int i=0; i<graph[cur].size(); i++) {
            int nxt = graph[cur][i];
            indegree[nxt]--;
            if(!indegree[nxt]) q.push(nxt);
        }
    }
    
    return 0;
}
