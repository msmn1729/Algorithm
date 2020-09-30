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

//https://www.acmicpc.net/problem/11053 가장 긴 증가하는 부분 수열

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, ans = 0;
    int ar[1001] = {}, dp[1001] = {};
    
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> ar[i];
        
        int mx = 0;
        for(int j=0; j<i; j++)
        {
            if(ar[i] > ar[j])
            {
                mx = max(mx, dp[j]);
            }
        }
        dp[i] = mx + 1;
        ans = max(ans, dp[i]);
    }
    cout << ans;
    
    return 0;
}

