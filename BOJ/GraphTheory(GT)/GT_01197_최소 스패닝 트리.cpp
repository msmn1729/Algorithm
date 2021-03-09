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

//https://www.acmicpc.net/problem/1197 최소 스패닝 트리

int parent[10001];
int ans;

int Find(int x) {
    if(parent[x] == x) return x; //루트
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y, int cost) {
    x = parent[x];
    y = parent[y];
    if(x == y) return;
    ans += cost;
    parent[x] = y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    priority_queue<tuple<int, int, int> > pq;
    int v, e;
    cin >> v >> e;
    for(int i=0; i<e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({-c, a, b});
    }
    
    for(int i=1; i<=v; i++) parent[i] = i;
    
    while(pq.size()) {
        int cost = -get<0>(pq.top());
        int a = get<1>(pq.top());
        int b = get<2>(pq.top());
        pq.pop();
        
        a = Find(a);
        b = Find(b);
        Union(a, b, cost);
    }
    cout << ans;
    
    return 0;
}
