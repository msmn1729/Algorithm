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

struct info {
    int st, ed, cost;
};

int parent[100001];

bool cmp(info a, info b) {
    return a.cost < b.cost;
}

int find(int a) {
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<info> v(m);
    
    for(int i=0; i<m; i++) {
        cin >> v[i].st >> v[i].ed >> v[i].cost;
    }
    sort(v.begin(), v.end(), cmp);
    
    for(int i=1; i<=n; i++) parent[i] = i;
    
    int ans = 0, cnt = 0;
    for(int i=0; i<m; i++) {
        int st = v[i].st;
        int ed = v[i].ed;
        int cost = v[i].cost;
        if(find(st) == find(ed)) continue;
        
        merge(st, ed);
        cnt++;
        ans += cost;
        if(cnt == n-2) break;
    }
    cout << ans;
    
    return 0;
}
