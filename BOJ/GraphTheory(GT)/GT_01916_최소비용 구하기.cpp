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

//https://www.acmicpc.net/problem/1916 최소비용 구하기

vector<pair<int, int> > v[1001];
int n, m;
int dist[1001];

void dijkstra(int start) {
    dist[start] = 0;
    
    priority_queue<pair<int, int> > pq;
    pq.push({0, start});
    
    while(pq.size()) {
        int cur_dist = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if(dist[cur_node] < cur_dist) continue; //더 큰 거리는 패스
        
        for(int i=0; i<v[cur_node].size(); i++) {
            int nxt_node = v[cur_node][i].first;
            int nxt_dist = v[cur_node][i].second;
            
            //경유해서 가는 경우가 더 최단 거리라면 갱신
            if(nxt_dist + cur_dist < dist[nxt_node]) {
                dist[nxt_node] = nxt_dist + cur_dist;
                pq.push({-dist[nxt_node], nxt_node});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    fill(dist, dist+1001, INF);
    cin >> n >> m;
    
    for(int i=0; i<m; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        v[s].push_back({e, c});
    }
    
    int start, arrival;
    cin >> start >> arrival;
    
    dijkstra(start);
    cout << dist[arrival];
    
    return 0;
}
