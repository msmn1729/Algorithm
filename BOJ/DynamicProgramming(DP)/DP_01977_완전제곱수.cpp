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

//https://www.acmicpc.net/problem/1944 완전제곱수

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int m, n;
    int dp[101] = {};
    cin >> m >> n;
    for(int i=1; i<=100; i++)
    {
        dp[i] = i*i;
    }
    int st = dp[(int)sqrt(m)] == m ? sqrt(m) : sqrt(m) + 1;
    int sum = 0;
    int mn = dp[st];
    bool flag = false;
    for(int i=st; i<=sqrt(n); i++)
    {
        flag = true;
        sum += dp[i];
    }
    if(!flag) cout << -1;
    else cout << sum << '\n' << mn;
    
    return 0;
}

