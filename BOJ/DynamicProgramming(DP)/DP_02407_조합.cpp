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

//https://www.acmicpc.net/problem/2407 조합

string stringAdd(string a, string b)
{
    int sum = 0;
    string result;
    while(a.size() || b.size() || sum)
    {
        if(a.size())
        {
            sum += a.back() - '0';
            a.pop_back();
        }
        if(b.size())
        {
            sum += b.back() - '0';
            b.pop_back();
        }
        result.push_back(sum % 10 + '0');
        sum /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string dp[101][101] = {};
    int n, m;
    cin >> n >> m;
    
    for(int i=0; i<=100; i++)
    {
        dp[i][0] = "1";
        for(int j=1; j<=100; j++) dp[i][j] = "0";
    }
    
    for(int i=1; i<=100; i++)
    {
        for(int j=1; j<=i; j++) dp[i][j] = stringAdd(dp[i-1][j-1], dp[i-1][j]);
    }
    
    cout << dp[n][m];
    
    return 0;
}
