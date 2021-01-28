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

//https://www.acmicpc.net/problem/9658 돌 게임 4

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    int dp[1001] = {};
    dp[2] = dp[4] = 1;
    
    cin >> n;
    for(int i=5; i<=n; i++) dp[i] = (dp[i-4] && dp[i-3] && dp[i-1])^1;
    cout << (dp[n] ? "SK" : "CY");
    
    return 0;
}
