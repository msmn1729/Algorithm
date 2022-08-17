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

struct info {
    int a, b, c;
};

int vis[201][201][201];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int max_a, max_b, max_c, a = 0, b = 0, c;
    cin >> max_a >> max_b >> max_c;
    c = max_c;
    
    vector<int> ans;
    queue<info> q;
    vis[a][b][c] = 1;
    q.push({a, b, c});
    
    while(q.size()) {
        a = q.front().a;
        b = q.front().b;
        c = q.front().c;
        q.pop();
        
        if(a == 0) ans.push_back(c);
        
        int na = 0, nb = 0, nc = 0;
        int sum_water = 0;
        
        // 1. a -> b
        sum_water = a + b;
        nb = min(max_b, sum_water);
        na = sum_water - nb;
        if(!vis[na][nb][c]) q.push({na, nb, c});
        vis[na][nb][c] = 1;
        
        // 2. b -> a
        sum_water = a + b;
        na = min(max_a, sum_water);
        nb = sum_water - na;
        if(!vis[na][nb][c]) q.push({na, nb, c});
        vis[na][nb][c] = 1;
        
        // 3. b -> c
        sum_water = b + c;
        nc = min(max_c, sum_water);
        nb = sum_water - nc;
        if(!vis[a][nb][nc]) q.push({a, nb, nc});
        vis[a][nb][nc] = 1;
        
        // 4. c -> b
        sum_water = b + c;
        nb = min(max_b, sum_water);
        nc = sum_water - nb;
        if(!vis[a][nb][nc]) q.push({a, nb, nc});
        vis[a][nb][nc] = 1;
        
        // 5. c -> a
        sum_water = a + c;
        na = min(max_a, sum_water);
        nc = sum_water - na;
        if(!vis[na][b][nc]) q.push({na, b, nc});
        vis[na][b][nc] = 1;
        
        // 6. a -> c
        sum_water = a + c;
        nc = min(max_c, sum_water);
        na = sum_water - nc;
        if(!vis[na][b][nc]) q.push({na, b, nc});
        vis[na][b][nc] = 1;
    }
    sort(ans.begin(), ans.end());
    
    for(int it : ans) cout << it << ' ';
    
    return 0;
}
