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

//https://www.acmicpc.net/problem/1463 1로 만들기

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, dp[1000001] = {};
    cin >> n;
    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + 1;
        if(i%2 == 0) dp[i] = min(dp[i], dp[i/2] + 1);
        if(i%3 == 0) dp[i] = min(dp[i], dp[i/3] + 1);
    }
    cout << dp[n];
    return 0;
}
