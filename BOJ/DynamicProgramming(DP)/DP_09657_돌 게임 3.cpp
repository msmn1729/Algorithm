#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int dp[1001] = {};
    dp[1]=dp[3]=dp[4]=1;
    
    for(int i=5; i<=n; i++)
    {
        if(!dp[i-4] || !dp[i-3] || !dp[i-1]) dp[i] = 1;
    }
    cout << (dp[n] ? "SK" : "CY");
    return 0;
}
