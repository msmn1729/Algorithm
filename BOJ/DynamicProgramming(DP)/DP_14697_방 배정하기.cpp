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
#include <bitset>
#define ll long long

using namespace std;

//https://www.acmicpc.net/problem/14697 방 배정하기

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    int dp[301] = {};
    dp[a] = dp[b] = dp[c] = 1;
    
    for(int i=2; i<=n; i++)
    {
        if(dp[i-a] == 1 || dp[i-b] == 1 || dp[i-c] == 1) dp[i] = 1;
    }
    cout << dp[n];
    return 0;
}
