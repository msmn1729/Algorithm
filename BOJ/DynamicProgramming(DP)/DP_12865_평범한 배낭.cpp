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

int n, k;
int weight[100], value[100];
int dp[101][100001];

int go(int i, int w) {
    if(dp[i][w]) return dp[i][w];
    if(i == n) return 0;
    
    int include = 0, not_include = 0;
    if(w+weight[i] <= k) include = go(i+1, w+weight[i]) + value[i];
    not_include = go(i+1, w);
    
    return dp[i][w] = max(include, not_include);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> weight[i] >> value[i];
    cout << go(0, 0);
    
    return 0;
}
