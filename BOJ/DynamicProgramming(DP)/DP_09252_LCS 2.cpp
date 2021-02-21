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

//https://www.acmicpc.net/problem/9252 LCS 2

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int dp[1001][1001] = {};
    
    string a, b;
    cin >> a >> b;

    for(int i=1; i<=b.size(); i++) {
        for(int j=1; j<=a.size(); j++) {
            if(b[i-1] == a[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    int x = (int)b.size();
    int y = (int)a.size();
    string result = "";
    
    while(dp[x][y]) {
        if(dp[x][y] == dp[x-1][y]) {
            x--;
            continue;
        }
        if(dp[x][y] == dp[x][y-1]) {
            y--;
            continue;
        }
        if(dp[x][y] == dp[x-1][y-1] + 1) {
            result = b[x-1] + result;
            x--; y--;
        }
    }
    cout << dp[b.size()][a.size()] << '\n';
    cout << result;
    
    return 0;
}
