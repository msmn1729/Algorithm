#include <unordered_map>
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

ll dp[65] = {1};

int go(ll idx) {
    if(idx == 0) return 0;
    for(int i=1; i<=63; i++) {
        if(idx < dp[i]) return !go(idx - dp[i-1]);
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    ll k;
    for(int i=1; i<=63; i++) dp[i] = dp[i-1] * 2;
    cin >> k;
    cout << go(k-1);
    
    return 0;
}

