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

using namespace std;

//https://www.acmicpc.net/problem/11725 트리의 부모 찾기

int n;
vector<vector<int> > g;
vector<int> parent_node;

void dfs(int start) {
    for(int i=0; i<g[start].size(); i++) {
        int nxt = g[start][i];
        if(parent_node[nxt]) continue;
        parent_node[nxt] = start;
        dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    g.resize(n+1);
    parent_node.resize(n+1);
    
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    parent_node[1] = 1; //시작점 방문처리
    dfs(1);
    for(int i=2; i<=n; i++) cout << parent_node[i] << '\n';

    return 0;
}
