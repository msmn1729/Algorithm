#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/16202 MST 게임

int parent[1010];

int find(int a) {
    if(parent[a] == 0) return a;
    return parent[a] = find(parent[a]);
}

bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return false;
    parent[a] = b;
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<tuple<int, int, int>> edges(m);
    
    int cost_val = 1;
    for(auto &[cost, st, ed] : edges) {
        cost = cost_val++;
        cin >> st >> ed;
    }
    
    int flag = 0;
    for(int i=0; i<k; i++)
    {
        if(flag) {
            cout << 0 << ' ';
            continue;
        }
        memset(parent, -1, sizeof(parent));
        int sum = 0;
        int cnt = 0;
        for(int j=0; j<edges.size(); j++) {
            int cost = get<0>(edges[j]);
            int st = get<1>(edges[j]);
            int ed = get<2>(edges[j]);
            if(!merge(st, ed)) continue;
            cnt++;
            sum += cost;
        }
        if(cnt < n-1) {
            cout << 0 << ' ';
            flag = 1;
        }
        else {
            if(edges.size()) edges.erase(edges.begin());
            cout << sum << ' ';
        }
    }
    
    return 0;
}
