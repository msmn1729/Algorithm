#include <bits/stdc++.h>

using namespace std;

vector<int> graph[20001];
int visited[20001];
int dist[20001];
int mx;

// 가장 먼 노드의 개수 반환
int BFS(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(int i=0; i<graph[cur].size(); i++) {
            int nxt = graph[cur][i];
            if(visited[nxt]) continue;
            dist[nxt] = dist[cur] + 1;
            mx = max(mx, dist[nxt]);
            visited[nxt] = 1;
            q.push(nxt);
        }
    }
    int ret = 0;
    for(int i=1; i<=2e4; i++) {
        if(dist[i] == mx) ret++;
    }
    return ret;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(auto v: edge) {
        int st = v[0];
        int ed = v[1];
        graph[st].push_back(ed);
        graph[ed].push_back(st);
    }
    answer = BFS(1);
    
    return answer;
}