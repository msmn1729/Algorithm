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

//https://www.acmicpc.net/problem/4948 베르트랑 공준

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int prime[300000] = {1, 1};
    int dp[300000] = {};
    for(int i=2; i<=sqrt(123456 * 2); i++) {
        if(prime[i]) continue;
        for(int j=i+i; j<=123456 * 2; j+=i) {
            prime[j] = 1;
        }
    }
    
    for(int i=2; i<=123456 * 2; i++) {
        if(!prime[i]) dp[i]++;
        dp[i] += dp[i-1];
    }

    while(1) {
        int in;
        cin >> in;
        if(!in) break;
        cout << dp[2*in] - dp[in] << '\n';
    }
    
    return 0;
}
