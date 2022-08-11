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

int parent[100001];

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
    int vCnt, eCnt;
    int st, ed, cost;
    cin >> vCnt >> eCnt;
    vector<info> graph;
    
    for(int i=0; i<eCnt; i++) {
        cin >> st >> ed >> cost;
        graph.push_back({st, ed, cost});
    }
    
    sort(graph.begin(), graph.end(), cmp);
    
    for(int i=1; i<=vCnt; i++) parent[i] = i;
    
    int ans = 0;
    for(int i=0; i<eCnt; i++) {
        st = graph[i].st;
        ed = graph[i].ed;
        cost = graph[i].cost;
        if(find(st) == find(ed)) continue;
        merge(st, ed);
        ans += cost;
    }
    cout << ans;
    
    return 0;
}
