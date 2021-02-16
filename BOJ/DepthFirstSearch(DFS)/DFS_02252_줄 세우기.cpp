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
int visit[32001];
stack<int> stk;

void dfs(int v) {
    visit[v] = 1;
    for(int i=0; i<graph[v].size(); i++) {
        int nv = graph[v][i];
        if(visit[nv]) continue;
        dfs(nv);
    }
    stk.push(v);
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
    }
    
    for(int i=1; i<=n; i++) {
        if(visit[i]) continue;
        dfs(i);
    }
    
    while(stk.size()) {
        cout << stk.top() << ' ';
        stk.pop();
    }
    
    return 0;
}
