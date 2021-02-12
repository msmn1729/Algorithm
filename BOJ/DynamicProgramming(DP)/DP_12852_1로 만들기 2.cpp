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

//https://www.acmicpc.net/problem/12852 1로 만들기 2

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> dp(n+1);
    vector<int> ans(n+1);
    
    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + 1;
        ans[i] = i-1;
        
        if(i%3 == 0) {
            if(dp[i] > dp[i/3]+1) {
                dp[i] = dp[i/3] + 1;
                ans[i] = i/3;
            }
        }
        if(i%2 == 0) {
            if(dp[i] > dp[i/2]+1) {
                dp[i] = dp[i/2] + 1;
                ans[i] = i/2;
            }
        }
    }
    cout << dp[n] << '\n';
    cout << n << ' ';
    for(; ans[n]; n = ans[n]) {
        cout << ans[n] << ' ';
    }
    
    return 0;
}
