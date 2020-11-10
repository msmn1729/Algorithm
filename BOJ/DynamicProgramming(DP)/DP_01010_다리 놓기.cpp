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

//https://www.acmicpc.net/problem/1010 다리 놓기

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t, a, b;
    cin >> t;
    int dp[30][30] = {};
    
    for(int i=0; i<30; i++) dp[i][0] = 1;
    
    for(int i=1; i<30; i++)
    {
        for(int j=1; j<=i; j++)
        {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    while(t--)
    {
        cin >> a >> b;
        cout << dp[b][a] << '\n';
    }
    
    return 0;
}
