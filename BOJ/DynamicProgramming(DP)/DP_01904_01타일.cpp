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
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/1904 01타일

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    int dp[1000001] = {0, 1, 2};
    
    for(int i=3; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= 15746;
    }
    cout << dp[n];
    
    return 0;
}
