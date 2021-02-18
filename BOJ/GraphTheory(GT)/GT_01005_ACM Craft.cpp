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

//https://www.acmicpc.net/problem/1005 ACM Craft

vector<int> graph[1001];
int vertex_time[1001];
int indegree[1001];
int dp[1001];
vector<int> t_sort;

void go(int x) {
    for(int i=0; i<graph[x].size(); i++) {
        int nx = graph[x][i];
        dp[nx] = max(dp[nx], dp[x] + vertex_time[nx]);
        if(--indegree[nx] == 0) go(nx);
    }
    t_sort.push_back(x);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t, n, k, w;
    cin >> t;
    
    while(t--) {
        cin >> n >> k;
        for(int i=1; i<=n; i++) graph[i].clear();
        fill(vertex_time, vertex_time+1001, 0);
        fill(dp, dp+1001, 0);
        fill(indegree, indegree+1001, 0);
        
        for(int i=1; i<=n; i++) {
            cin >> vertex_time[i];
            dp[i] = vertex_time[i];
        }
        for(int i=1; i<=k; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            indegree[b]++;
        }
        
        cin >> w;
        
        for(int i=1; i<=n; i++) {
            if(indegree[i]) continue;
            go(i);
        }
        cout << dp[w] << '\n';
    }
    
    return 0;
}
