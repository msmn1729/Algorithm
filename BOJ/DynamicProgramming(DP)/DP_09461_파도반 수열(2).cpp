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
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/9461 파도반 수열

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t, n;
    cin >> t;
    vector<ll> dp(101);
    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = dp[5] = 2;
    
    for(int i=6; i<=100; i++) dp[i] = dp[i-1] + dp[i-5];
    
    while(t--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
    
    return 0;
}
