#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int n;
int finded = -1;
int visited[10001];
vector<int> adj[10001];
vector<int> cycle;

void findCycle(int cur, int prev) {
    if(visited[cur]) {
        finded = cur;
        cycle.push_back(cur);
        return;
    }
    
    visited[cur] = 1;
    for(auto nxt : adj[cur]) {
        // 무방향 그래프에서의 사이클이므로 직접 연결된 두 노드를 제외하기 위함
        if(nxt == prev) continue;
        findCycle(nxt, cur);
        
        if(finded == 0)
            return;
        
        // 찾은 사이클의 시작점이 자신인 경우
        // cycle에 자신을 두번 push하는 것을 방지
        if(finded == cur) {
            finded = 0;
            return;
        }
        
        if(finded > 0) {
            cycle.push_back(cur);
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++) {
        int st, ed;
        cin >> st >> ed;
        adj[st].push_back(ed);
        adj[ed].push_back(st);
    }
    
    findCycle(1, 1);
    sort(cycle.begin(), cycle.end());
    
    cout << cycle.size() << '\n';
    for(auto i : cycle) cout << i << ' ';
    
    return 0;
}
