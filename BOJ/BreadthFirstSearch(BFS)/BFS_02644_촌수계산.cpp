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

int n, x, y;
vector<int> graph[101];
int dist[101];

void bfs() {
    queue<int> q;
    q.push(x);
    
    while(q.size()) {
        int cur = q.front();
        q.pop();
        
        for(int i=0; i<graph[cur].size(); i++) {
            int nxt = graph[cur][i];
            if(dist[nxt]) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    cin >> x >> y;
    int m;
    cin >> m;
    
    for(int i=0; i<m; i++) {
        int st, ed;
        cin >> st >> ed;
        graph[st].push_back(ed);
        graph[ed].push_back(st);
    }
    bfs();
    if(dist[y] == 0) cout << -1;
    else cout << dist[y];
    
    return 0;
}
