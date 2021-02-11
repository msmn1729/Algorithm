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

//https://www.acmicpc.net/problem/2096 내려가기

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int max_dp[4] = {}, min_dp[4] = {};
    int n, max_a, max_b, max_c, min_a, min_b, min_c;
    cin >> n;
    
    for(int i=1; i<=n; i++) {
        max_a = max(max_dp[1], max_dp[2]);
        max_b = max(max(max_dp[1], max_dp[2]), max_dp[3]);
        max_c = max(max_dp[2], max_dp[3]);
        
        min_a = min(min_dp[1], min_dp[2]);
        min_b = min(min(min_dp[1], min_dp[2]), min_dp[3]);
        min_c = min(min_dp[2], min_dp[3]);
        
        for(int j=1; j<=3; j++) cin >> max_dp[j];
        memcpy(min_dp, max_dp, sizeof(max_dp));
        
        max_dp[1] += max_a;
        max_dp[2] += max_b;
        max_dp[3] += max_c;
        
        min_dp[1] += min_a;
        min_dp[2] += min_b;
        min_dp[3] += min_c;
    }
    
    int max_ans = 0, min_ans = 2e9;
    for(int i=1; i<=3; i++) {
        max_ans = max(max_ans, max_dp[i]);
        min_ans = min(min_ans, min_dp[i]);
    }
    cout << max_ans << ' ' << min_ans;
    
    return 0;
}
