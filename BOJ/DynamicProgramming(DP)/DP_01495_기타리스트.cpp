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
#define ll long long

using namespace std;

//https://www.acmicpc.net/problem/1495 기타리스트

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, s, m, t;
    bool dp[101][1001] = {};
    cin >> n >> s >> m;
    dp[0][s] = true;
    
    for(int i=1; i<=n; i++)
    {
        cin >> t;
        for(int j=0; j<=m; j++)
        {
            if(dp[i-1][j])
            {
                if(j+t <= m)
                {
                    dp[i][j+t] = true;
                }
                if(j-t >= 0)
                {
                    dp[i][j-t] = true;
                }
            }
        }
    }
    int ans = -1;
    for(int i=0; i<=m; i++)
    {
        if(dp[n][i])
        {
            ans = max(ans, i);
        }
    }
    cout << ans;
    
    
    return 0;
}
