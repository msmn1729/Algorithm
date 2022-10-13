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
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    int dp[3] = {};
    int prev_dp[3] = {};
    dp[0] = dp[1] = dp[2] = 1;
    
    for(int i=2; i<=n; i++) {
        for(int j=0; j<3; j++) {
            prev_dp[j] = dp[j];
        }
        dp[0] = (prev_dp[1] + prev_dp[2]) % 9901;
        dp[1] = (prev_dp[0] + prev_dp[2]) % 9901;
        dp[2] = (prev_dp[0] + prev_dp[1] + prev_dp[2]) % 9901;
    }
    
    cout << (dp[0] + dp[1] + dp[2]) % 9901;
    
    return 0;
}
