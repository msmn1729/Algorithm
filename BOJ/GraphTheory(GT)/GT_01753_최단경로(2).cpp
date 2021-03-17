#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <iomanip>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/1753 최단경로

struct info {
    int end, cost;
};

int v, e, start;
vector<info> graph[20001];
int dist[20001] = {};

void dijkstra(int start) {
    fill(dist, dist+v+1, INF);
    dist[start] = 0;
    
    priority_queue<pair<int, int> > pq;
    pq.push({dist[start], start});
    
    while(pq.size()) {
        int cur = pq.top().second;
        pq.pop();
        
        for(int i=0; i<graph[cur].size(); i++) {
            int nxt = graph[cur][i].end;
            int nxt_cost = graph[cur][i].cost;
            
            if(dist[nxt] > dist[cur] + nxt_cost) {
                dist[nxt] = dist[cur] + nxt_cost;
                pq.push({-dist[nxt], nxt});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> v >> e >> start;
    for(int i=0; i<e; i++) {
        int st, ed, cost;
        cin >> st >> ed >> cost;
        graph[st].push_back({ed, cost});
    }
    
    dijkstra(start);
    
    for(int i=1; i<=v; i++) {
        if(dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
    
    return 0;
}
