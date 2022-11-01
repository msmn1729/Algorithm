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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    int dist[11][11] = {};
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> dist[i][j];
        }
    }
    
    vector<int> v(n);
    for(int i=0; i<n; i++) v[i] = i;
    
    int ans = 2e9 + 11;
    
    do {
        int sum = 0, flag = 0, cur, nxt;
        
        for(int i=0; i<n-1; i++) {
            int cur = v[i];
            int nxt = v[i+1];
            if(dist[cur][nxt] == 0) {
                flag = 1;
                break;
            }
            sum += dist[cur][nxt];
        }
        
        cur = v[n-1];
        nxt = v[0];
        if(flag || dist[cur][nxt] == 0) continue;
        sum += dist[cur][nxt];
        ans = min(ans, sum);
    } while(next_permutation(v.begin(), v.end()));
    
    cout << ans;
    
    return 0;
}
