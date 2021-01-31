#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <map>
#include <iomanip>
#include <list>
#include <stack>
#include <cstring>
#include <cmath>
#include <set>
#include <unordered_map>
#include <bitset>
#define ll long long
#define INF 2e9

using namespace std;

//https://www.acmicpc.net/problem/1753 최단경로

int v, e, start;
int dist[20001];
vector<pair<int, int> > graph[20001];

void dijkstra() {
    dist[start] = 0;
    priority_queue<pair<int, int> > q;
    q.push({0, start});
    
    while(q.size()) {
        int wt = -q.top().first;
        int cur = q.top().second;
        q.pop();
         
        if(dist[cur] < wt) continue;
        for(int i=0; i<graph[cur].size(); i++) {
            int nxt = graph[cur][i].first;
            int nxt_wt = graph[cur][i].second;
            
            if(dist[nxt] > wt + nxt_wt) {
                dist[nxt] = wt + nxt_wt;
                q.push({-dist[nxt], nxt});
            }
        }
    }
    for(int i=1; i<=v; i++) {
        if(dist[i] == INF) cout << "INF";
        else cout << dist[i];
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> v >> e >> start;
    for(int i=0; i<e; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
    }
    fill(dist, dist+20001, INF);
    dijkstra();
    
    return 0;
}
