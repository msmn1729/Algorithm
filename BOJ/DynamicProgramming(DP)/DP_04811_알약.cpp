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

//https://www.acmicpc.net/problem/4811 알약

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    ll dp[31][61] = {}; //완전한 알약, 반쪽 알약

    for(int h=1; h<=60; h++) dp[0][h] = 1;
    
    for(int w=1; w<=30; w++)
    {
        for(int h=0; h<=60; h++)
        {
            if(w + h/2 > 30) continue;
            if(h == 0) dp[w][h] = dp[w-1][h+1]; //반쪽 알약이 없을 때
            else dp[w][h] = dp[w-1][h+1] + dp[w][h-1];
        }
    }
    
    while(cin >> n && n) cout << dp[n][0] << '\n';

    return 0;
}
