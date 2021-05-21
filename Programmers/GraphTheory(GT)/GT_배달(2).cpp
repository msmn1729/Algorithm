#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <iomanip>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define ll long long
#define INF 1e9

using namespace std;

vector<pair<int, int> > graph[51];
int dist[51];

void dijkstra(int start) {
    priority_queue<pair<int, int> > pq;
    pq.push({0, start});
    
    while(pq.size()) {
        int cur = pq.top().second;
        pq.pop();
        
        for(int i=0; i<graph[cur].size(); i++) {
            int nxt_cost = graph[cur][i].second;
            int nxt = graph[cur][i].first;
            
            if(dist[nxt] > dist[cur] + nxt_cost) {
                dist[nxt] = dist[cur] + nxt_cost;
                pq.push({-dist[nxt], nxt});
            }
        }
    }
}

int solution(int n, vector<vector<int> > road, int k) {
    int answer = 0;
    
    for(int i=0; i<road.size(); i++) {
        int st = road[i][0];
        int ed = road[i][1];
        int cost = road[i][2];
        graph[st].push_back({ed, cost});
        graph[ed].push_back({st, cost});
    }
    
    for(int i=1; i<=n; i++) dist[i] = INF;
    dist[1] = 0;
    
    dijkstra(1);
    
    for(int i=1; i<=n; i++) {
        cout << i << " : " << dist[i] << '\n';
        if(dist[i] <= k) answer++;
    }
    
    return answer;
}

int main() {
    
    solution(5, {{1,2,1}, {2,3,3}, {5,2,2}, {1,4,2}, {5,3,1}, {5,4,2}}, 3);
    
    return 0;
}
