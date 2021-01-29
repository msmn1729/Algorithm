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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k, w, v;
    cin >> n >> k;
    int dp[100001] = {};
    
    while(cin >> w >> v) {
        for(int i=k; i>=w; i--) dp[i] = max(dp[i], dp[i-w] + v);
    }
    cout << dp[k];
    
    return 0;
}
