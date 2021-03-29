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
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/14002 가장 긴 증가하는 부분 수열 4

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int dp[1001] = {}; // dp[a] : a번째 원소를 마지막으로 하는 LIS의 길이
    int n, ar[1001] = {}, prev[1001] = {};
    cin >> n;
    for(int i=1; i<=n; i++) cin >> ar[i];

    int ans = 0;
    int ans_idx = 0;
    for(int i=1; i<=n; i++) {
        dp[i] = 1;
        for(int j=1; j<i; j++) {
            if(ar[j] >= ar[i]) continue;
            if(dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if(ans < dp[i]) {
            ans = dp[i];
            ans_idx = i;
        }
    }

    int idx = ans_idx;
    vector<int> ans_order;
    for(int i=0; i<ans; i++) {
        ans_order.push_back(ar[idx]);
        idx = prev[idx];
    }
    reverse(ans_order.begin(), ans_order.end());

    cout << ans << '\n';
    for(int it: ans_order) cout << it << ' ';

    return 0;
}
