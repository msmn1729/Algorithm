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
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/1504 특정한 최단 경로

vector<pair<int, int> > graph[801];
int dist[801];
int n, e;

int dijkstra(int start, int end) {
    fill(dist, dist+n+1, INF);
    dist[start] = 0;
    
    priority_queue<pair<int, int> > pq;
    pq.push({0, start});
    
    while(pq.size()) {
        int cur_cost = -pq.top().first;
        int cur_vertex = pq.top().second;
        pq.pop();
        
        if(dist[cur_vertex] < cur_cost) continue;
        
        for(int i=0; i<graph[cur_vertex].size(); i++) {
            int nxt_cost = cur_cost + graph[cur_vertex][i].first;
            int nxt_vertex = graph[cur_vertex][i].second;
            if(dist[nxt_vertex] > nxt_cost) {
                dist[nxt_vertex] = nxt_cost;
                pq.push({-nxt_cost, nxt_vertex});
            }
        }
    }
    return dist[end];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> e;
    for(int i=0; i<e; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        graph[a].push_back({cost, b});
        graph[b].push_back({cost, a});
    }
    
    int v1, v2;
    cin >> v1 >> v2;
    
    int ans1 = 0, ans2 = 0;
    ans1 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, n); //최대 3e9
    ans2 = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, n);
    if(0 < ans1 && ans1 < ans2) cout << ans1;
    else if(0 < ans2 && ans2 < ans1) cout << ans2;
    else cout << -1;
    
    return 0;
}
