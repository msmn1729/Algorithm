#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(1), r_v(1);
    int rock[300001] = {};
    int dp[300001] = {}, r_dp[300001] = {}; // dp[a]: a번째 돌에서의 LIS 길이

    for(int i=0; i<n; i++) cin >> rock[i];

    // 정방향 LIS
    for(int i=0; i<n; i++) {
        if(v.back() < rock[i]) {
            dp[i] = v.size();
            v.push_back(rock[i]);
        }
        else {
            auto it = lower_bound(v.begin(), v.end(), rock[i]);
            *it = rock[i];
            dp[i] = it - v.begin();
        }
    }

    // 역방향 LIS
    for(int i=n-1; i>=0; i--) {
        if(r_v.back() < rock[i]) {
            r_dp[i] = r_v.size();
            r_v.push_back(rock[i]);
        }
        else {
            auto it = lower_bound(r_v.begin(), r_v.end(), rock[i]);
            *it = rock[i];
            r_dp[i] = (it - r_v.begin());
        }
    }

    // 바이토닉 연산
    int ans = 1;
    for(int i=0; i<n; i++) {
        ans = max(ans, dp[i] + r_dp[i] - 1);
    }
    cout << ans;

    return 0;
}
