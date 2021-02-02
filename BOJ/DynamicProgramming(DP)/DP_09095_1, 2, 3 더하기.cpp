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

//https://www.acmicpc.net/problem/9095 1, 2, 3 더하기

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t, n;
    cin >> t;
    
    int dp[11] = {0, 1, 2, 4};
    for(int i=4; i<=11; i++) dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
    while(t--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
    
    return 0;
}
