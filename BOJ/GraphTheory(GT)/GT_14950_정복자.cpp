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

int parent[10001];

struct info {
    int st, ed, cost;
};

bool cmp(info a, info b) {
    return a.cost < b.cost;
}

int find(int a) {
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int main() {
    int n, m, t;
    cin >> n >> m >> t;
    vector<info> graph(m);
    
    for(int i=0; i<m; i++) {
        cin >> graph[i].st >> graph[i].ed >> graph[i].cost;
    }
    
    sort(graph.begin(), graph.end(), cmp);
    
    for(int i=1; i<=n; i++) parent[i] = i;
    
    int ans = 0;
    int cnt = 0;
    for(int i=0; i<m; i++) {
        int st = graph[i].st;
        int ed = graph[i].ed;
        int cost = graph[i].cost;
        if(find(st) == find(ed)) continue;
        ans += cost + t * cnt++;
        merge(st, ed);
    }
    cout << ans;
    
    return 0;
}
