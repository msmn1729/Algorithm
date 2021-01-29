#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <map>
#include <iomanip>
#include <list>
#include <stack>
#include <cstring>
#include <cmath>
#include <set>
#include <unordered_map>
#include <bitset>
#define ll long long

using namespace std;

//https://www.acmicpc.net/problem/12865 평범한 배낭

int dp[101][100001] = {};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<pair<int, int> > item(k+1);
    
    for(int i=1; i<=n; i++) cin >> item[i].first >> item[i].second;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            if(item[i].first <= j) dp[i][j] = dp[i-1][j-item[i].first] + item[i].second;
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }
    cout << dp[n][k];
    
    return 0;
}
