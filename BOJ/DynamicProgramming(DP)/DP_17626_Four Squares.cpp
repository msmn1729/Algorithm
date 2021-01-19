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

//https://www.acmicpc.net/problem/17626 Four Squares

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, i, j;
    cin >> n;
    int dp[50001] = {};
    
    for(i=1; i<=n; i++) {
        dp[i] = 4;
        for(j=1; j*j<=i; j++) {
            if(j*j == i) dp[i] = 1;
            dp[i] = min(dp[i], dp[i-j*j] + dp[j*j]);
        }
    }
    cout << dp[n];
    
    return 0;
}
