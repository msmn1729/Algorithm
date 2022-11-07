#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <cmath>
#include <cstring>
#include <stack>
#include <unordered_map>
#include <set>
#define ll long long
#define INF 1e9
using namespace std;

vector<int> parent, check;

void dfs(int node) {
    if(check[node]) return;
    check[node] = 1;
    dfs(parent[node]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t, n;
    cin >> t;
    
    while(t--) {
        cin >> n;
        parent.assign(n+1, 0);
        check.assign(n+1, 0);
        
        for(int i=1; i<=n; i++) {
            cin >> parent[i];
        }
        
        int ans = 0;
        for(int i=1; i<=n; i++) {
            if(check[i]) continue;
            dfs(i);
            ans++;
        }
        cout << ans << '\n';
    }
    
    return 0;
}
