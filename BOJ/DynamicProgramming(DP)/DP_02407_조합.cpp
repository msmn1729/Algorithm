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

using namespace std;

//https://www.acmicpc.net/problem/2407 조합

string dp[101][101];

string stringAdd(string a, string b)
{
    int sum = 0;
    string result = "";
    
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
        result += ((sum%10) + '0');
        sum /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

string combination(int n, int m)
{
    if(n == m || m == 0) return "1";
    if(dp[n][m].empty()) return dp[n][m] = stringAdd(combination(n-1, m-1), combination(n-1, m));
    return dp[n][m];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    cout << combination(n, m);

    return 0;
}
