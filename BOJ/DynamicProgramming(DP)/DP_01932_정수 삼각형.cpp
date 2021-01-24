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

//https://www.acmicpc.net/problem/1932 정수 삼각형

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int dp[502] = {};
    int n, i, j, in, ans = -2e9;
    cin >> n;
    for(i=1; i<=n; i++) {
        for(j=i; j>=1; j--) {
            cin >> in;
            ans = max(ans, dp[j] = max(dp[j], dp[j-1]) + in);
        }
    }
    cout << ans;

    return 0;
}
