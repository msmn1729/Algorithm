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

//https://www.acmicpc.net/problem/2579 계단 오르기

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    int ar[301] = {};
    int dp[301] = {};
    cin >> n;
    
    for(int i=1; i<=n; i++) {
        cin >> ar[i];
    }
    dp[1] = ar[1];
    dp[2] = ar[1]+ar[2];
    
    for(int i=3; i<=n; i++) {
        dp[i] = max(dp[i-3]+ar[i-1], dp[i-2]) + ar[i];
    }
    cout << dp[n];
    
    return 0;
}
