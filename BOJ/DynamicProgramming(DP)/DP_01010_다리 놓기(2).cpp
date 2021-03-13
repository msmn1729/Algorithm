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

//https://www.acmicpc.net/problem/1010 다리 놓기

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    int dp[31][31] = {};
    for(int i=0; i<=30; i++) dp[i][0] = 1;
    for(int i=1; i<=30; i++) {
        for(int j=1; j<=i; j++) dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
    }
    while(n--) {
        int a, b;
        cin >> a >> b;
        cout << dp[b][a] << '\n';
    }
    
    return 0;
}
