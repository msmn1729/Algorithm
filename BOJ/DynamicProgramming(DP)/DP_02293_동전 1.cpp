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

//https://www.acmicpc.net/problem/2293 동전 1

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    int ar[101] = {}, dp[10001] = {};
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> ar[i];
    dp[0] = 1;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            if(j - ar[i] < 0) continue;
            dp[j] += dp[j - ar[i]];
        }
    }
    cout << dp[k];
    
    return 0;
}
