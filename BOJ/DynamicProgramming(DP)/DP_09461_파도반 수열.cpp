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

using namespace std;

//https://www.acmicpc.net/problem/9461 파도반 수열

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t, n;
    ll dp[101] = {};
    dp[1] = dp[2] = dp[3] = 1;
    for(int i=4; i<=100; i++) dp[i] = dp[i-3] + dp[i-2];
    
    cin >> t;
    while(t--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
    
    return 0;
}
