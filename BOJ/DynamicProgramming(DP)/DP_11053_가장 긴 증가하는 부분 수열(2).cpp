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

//https://www.acmicpc.net/problem/11053 가장 긴 증가하는 부분 수열

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int ar[1001] = {}, dp[1001] = {};
    int n, ans = 0;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> ar[i];
    for(int i=1; i<=n; i++) {
        int mx = 0;
        for(int j=1; j<i; j++) {
            if(ar[i] <= ar[j]) continue;
            mx = max(mx, dp[j]);
        }
        dp[i] = mx + 1;
        ans = max(ans, dp[i]);
    }
    cout << ans;
    
    return 0;
}
