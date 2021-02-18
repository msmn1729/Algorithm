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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t, n, k, w;
    cin >> t;
    
    while(t--) {
        
        cin >> n >> k;
        
        vector<int> graph[1001] = {};
        int vertex_time[1001] = {};
        int dp[1001] = {};
        int indegree[1001] = {};
        
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
        
        queue<int> q;
        for(int i=1; i<=n; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        while(q.size()) {
            int x = q.front();
            q.pop();
            for(int &nxt: graph[x]) {
                dp[nxt] = max(dp[nxt], dp[x] + vertex_time[nxt]);
                if(--indegree[nxt] == 0) q.push(nxt);
            }
        }
        cout << dp[w] << '\n';
    }
    
    return 0;
}
