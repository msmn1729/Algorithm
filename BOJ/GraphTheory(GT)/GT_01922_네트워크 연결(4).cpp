#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <cmath>
#include <cstring>
#include <stack>
#include <unordered_map>
#include <set>
#define ll long long
using namespace std;

struct info {
    int st, ed, cost;
};

int n, m;
vector<info> graph;
int parent[1001];

bool cmp(info a, info b) {
    return a.cost < b.cost;
}

int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x < y) parent[y] = x;
    else parent[x] = y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int ans = 0;
    cin >> n >> m;
    int st, ed, cost;
    for(int i=0; i<m; i++) {
        cin >> st >> ed >> cost;
        graph.push_back({st, ed, cost});
    }
    
    for(int i=1; i<=n; i++) parent[i] = i;
    
    sort(graph.begin(), graph.end(), cmp);
    
    for(int i=0; i<m; i++) {
        st = graph[i].st;
        ed = graph[i].ed;
        cost = graph[i].cost;
        if(find(st) == find(ed)) {
            continue;
        }
        merge(st, ed);
        ans += cost;
    }
    
    cout << ans;
    
    return 0;
}
