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
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/2579 계단 오르기

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int ar[330] = {};
    int dp[330] = {}; //dp[a]: a번째 계단을 밟지 않았을 때 밟지 않은 계단들의 최소합
    int sum = 0;
    
    for(int i=1; i<=n; i++) {
        cin >> ar[i];
        sum += ar[i];
    }
    
    dp[1] = ar[1];
    dp[2] = ar[2];
    dp[3] = ar[3];
    for(int i=4; i<=n; i++) {
        dp[i] = min(dp[i-2], dp[i-3]) + ar[i];
    }
    cout << sum - min(dp[n-1], dp[n-2]);
    
    return 0;
}
