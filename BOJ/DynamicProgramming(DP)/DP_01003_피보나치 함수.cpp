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

using namespace std;

//https://www.acmicpc.net/problem/1003 피보나치 함수
//솔클

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int dp[2][41] = {};
    dp[0][0] = 1;
    dp[1][1] = 1;
    for(int i=2; i<=40; i++)
    {
        dp[0][i] = dp[0][i-2] + dp[0][i-1];
        dp[1][i] = dp[1][i-2] + dp[1][i-1];
    }
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << dp[0][n] << ' ' << dp[1][n] << '\n';
    }
    
    return 0;
}
