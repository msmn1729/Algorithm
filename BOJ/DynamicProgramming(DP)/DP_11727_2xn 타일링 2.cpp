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

//https://www.acmicpc.net/problem/11727 2×n 타일링 2

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int dp[1001] = {};
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 3;
    
    for(int i=3; i<=n; i++) {
        dp[i] = 2*dp[i-2] + dp[i-1];
        dp[i] %= 10007;
    }
    cout << dp[n];
    
    return 0;
}
