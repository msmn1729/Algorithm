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

//https://www.acmicpc.net/problem/11055 가장 큰 증가 부분 수열

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    int dp[1001] = {};
    int ar[1001] = {};
    int ans = 0;
    
    for(int i=1; i<=n; i++) {
        cin >> ar[i];
        dp[i] = ar[i];
        for(int j=1; j<=i; j++) {
            if(ar[j] >= ar[i]) continue;
            dp[i] = max(dp[i], dp[j]+ar[i]);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
    
    return 0;
}
