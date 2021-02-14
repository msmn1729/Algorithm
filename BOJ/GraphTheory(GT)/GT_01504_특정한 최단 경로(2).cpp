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

//https://www.acmicpc.net/problem/1504 특정한 최단 경로

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, e;
    int dist[801][801] = {};
    
    cin >> n >> e;
    for(int i=1; i<=n; i++) {
        fill(dist[i], dist[i]+n+1, INF);
        dist[i][i] = 0;
    }
    
    for(int i=0; i<e; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        dist[a][b] = dist[b][a] = cost;
    }
    
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    int v1, v2;
    cin >> v1 >> v2;
    
    int path1 = dist[1][v1] + dist[v1][v2] + dist[v2][n];
    int path2 = dist[1][v2] + dist[v2][v1] + dist[v1][n];
    if(0 < path1 && path1 < path2) cout << path1;
    else if(0 < path2 && path2 < path1) cout << path2;
    else cout << -1;
    
    return 0;
}
