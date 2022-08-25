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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> adjacency[n+1];
    vector<int> dp(n+1);
    
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adjacency[b].push_back(a); // 나의 선수과목을 찾기위함
    }
    
    for(int i=1; i<=n; i++) {
        dp[i] = 1;
        for(int j=0; j<adjacency[i].size(); j++) {
            int prev = adjacency[i][j];
            dp[i] = max(dp[i], dp[prev] + 1);
        }
    }
    
    for(int i=1; i<=n; i++) cout << dp[i] << ' ';
    
    return 0;
}
