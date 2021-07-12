#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <iomanip>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int r, c;
    int dp[1001][1001] = {};
    cin >> r >> c;
    
    for(int i=0; i<r; i++) {
        string s;
        cin >> s;
        for(int j=0; j<c; j++) dp[i][j] = s[j] - '0';
    }
    
    int ans = dp[0][0];
    for(int i=1; i<r; i++) {
        for(int j=1; j<c; j++) {
            if(dp[i][j] == 0) continue;
            dp[i][j] = min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]}) + 1;
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans*ans;
    
    return 0;
}
