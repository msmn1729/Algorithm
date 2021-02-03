#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <map>
#include <iomanip>
#include <list>
#include <stack>
#include <cstring>
#include <cmath>
#include <set>
#include <unordered_map>
#include <bitset>
#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/1967 트리의 지름

vector<pair<int ,int> > v[10001];
int visit[10001];
int diameter_vertex;
int max_weight;

int dfs(int start, int weight) {
    visit[start] = 1;
    
    if(max_weight < weight) {
        max_weight = weight;
        diameter_vertex = start;
    }
    
    for(auto it: v[start]) {
        int nxt = it.first;
        if(visit[nxt]) continue;
        dfs(it.first, weight + it.second);
    }
    
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    for(int i=0; i<n-1; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        v[s].push_back({e, w});
        v[e].push_back({s, w});
    }
    dfs(1, 0);
    fill(visit, visit+10001, 0);
    dfs(diameter_vertex, 0);
    cout << max_weight;
    
    return 0;
}
