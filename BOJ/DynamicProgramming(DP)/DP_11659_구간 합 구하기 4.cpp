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

//https://www.acmicpc.net/problem/11659 구간 합 구하기 4

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    ll dp[100001] = {};
    cin >> n >> m;
    
    for(int i=1; i<=n; i++) {
        cin >> dp[i];
        dp[i] += dp[i-1];
    }
    while(m--) {
        int a, b;
        cin >> a >> b;
        cout << dp[b]-dp[a-1] << '\n';
    }
    
    return 0;
}
