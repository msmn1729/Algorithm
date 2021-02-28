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

//https://www.acmicpc.net/problem/1958 LCS 3

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string a, b, c;
    cin >> a >> b >> c;
    int dp[101][101][101] = {};
    int as = (int)a.size();
    int bs = (int)b.size();
    int cs = (int)c.size();
    
    for(int i=1; i<=as; i++) {
        for(int j=1; j<=bs; j++) {
            for(int k=1; k<=cs; k++) {
                if(a[i-1] == b[j-1] && b[j-1] == c[k-1]) dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                else dp[i][j][k] = max(max(dp[i-1][j][k], dp[i][j-1][k]), dp[i][j][k-1]);
            }
        }
    }
    cout << dp[as][bs][cs];
    
    return 0;
}
