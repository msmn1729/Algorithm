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
// 21:42~

int n, x, y;
int ar[101][101];
int visited[101];

int dfs(int depth, int x) {
//    cout << x << '\n';
    if(x == y) {
        cout << depth;
        exit(0);
    }
    visited[x] = 1;
    for(int i=1; i<=n; i++) {
        if(!ar[x][i]) continue;
        if(visited[i]) continue;
        dfs(depth + 1, i);
        visited[i] = 0;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    cin >> x >> y;
    int m;
    cin >> m;
    
    for(int i=0; i<m; i++) {
        int st, ed;
        cin >> st >> ed;
        ar[st][ed] = ar[ed][st] = 1;
    }
    cout << dfs(0, x);
    
    return 0;
}
