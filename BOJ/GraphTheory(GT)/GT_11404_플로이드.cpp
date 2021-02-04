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

//https://www.acmicpc.net/problem/11404 플로이드

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int ar[101][101] = {};
    int n, m, i, j, k;
    cin >> n >> m;
    
    for(i=0; i<101; i++) fill(ar[i], ar[i]+101, INF);
    
    for(i=0; i<m; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        ar[s][e] = min(ar[s][e], w);
    }
    
    for(k=1; k<=n; k++) {
        for(i=1; i<=n; i++) {
            for(j=1; j<=n; j++) {
                if(i == j) continue;
                ar[i][j] = min(ar[i][j], ar[i][k] + ar[k][j]);
            }
        }
    }
    
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            if(ar[i][j] == INF) cout << 0 << ' ';
            else cout << ar[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

