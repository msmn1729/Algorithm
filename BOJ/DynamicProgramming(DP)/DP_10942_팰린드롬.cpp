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

//https://www.acmicpc.net/problem/10942 팰린드롬?

int ar[2001];
int dp[2001][2001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> ar[i];
        dp[i][i] = 1;
    }
    
    for(int i=1; i<n; i++) dp[i][i+1] = ar[i] == ar[i+1];
    
    for(int len=1; len<=n; len++) {
        for(int st=1; st+len<=n; st++) {
            int ed = st+len;
            if((ar[st] == ar[ed]) && dp[st+1][ed-1]) dp[st][ed] = 1;
        }
    }
    
    cin >> m;
    while(m--) {
        int a, b;
        cin >> a >> b;
        cout << dp[a][b] << '\n';
    }
    
    return 0;
}
