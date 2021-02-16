#include <unordered_map>
#include <algorithm>
#include <iostream>
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

//https://www.acmicpc.net/problem/2252 줄 세우기

int n, m;
vector<int> graph[32001];
int indegree[32001];
int ans[32001];

void topologicalSort() {
    //1. 진입차수 0이면 큐에 삽입
    queue<int> q;
    for(int i=1; i<=n; i++) {
        if(indegree[i] == 0) q.push(i);
    }
    
    //정확히 n개의 노드를 방문해야 위상정렬이 완전히 수행됨
    for(int i=1; i<=n ;i++) {
        //모두 방문하기전에 큐가 빈다면 사이클
        if(q.empty()) return;
        
        //2. 큐에서 빼면서 진출간선 제거
        int x = q.front();
        q.pop();
        ans[i] = x;
        
        for(int j=0; j<graph[x].size(); j++) {
            int nx = graph[x][j];
            if(--indegree[nx] == 0) q.push(nx);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    topologicalSort();
    for(int i=1; i<=n; i++) {
        cout << ans[i] << ' ';
    }
    
    return 0;
}
