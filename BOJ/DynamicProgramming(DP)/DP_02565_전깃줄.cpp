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

//https://www.acmicpc.net/problem/2565 전깃줄

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    int dp[101] = {};
    vector<pair<int, int> > v(1);
    
    cin >> n;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    
    sort(v.begin(), v.end());
    
    int cnt_mx = 0;
    for(int i=1; i<=n; i++) {
        int mx = 0;
        for(int j=1; j<i; j++) {
            if(v[i].second < v[j].second) continue;
            mx = max(mx, dp[j]);
        }
        dp[i] = mx + 1;
        cnt_mx = max(cnt_mx, dp[i]);
    }
    cout << n - cnt_mx;
    
    return 0;
}
