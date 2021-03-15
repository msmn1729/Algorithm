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

//https://www.acmicpc.net/problem/2579 계단 오르기

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int ar[330] = {};
    int dp[330][3] = {};
    for(int i=1; i<=n; i++) cin >> ar[i];
    
    dp[1][1] = ar[1];
    for(int i=2; i<=n; i++) {
        dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + ar[i];
        dp[i][2] = dp[i-1][1] + ar[i];
    }
    cout << max(dp[n][1], dp[n][2]);

    return 0;
}
