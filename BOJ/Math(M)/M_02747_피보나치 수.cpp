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

//https://www.acmicpc.net/problem/2747 피보나치 수

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int dp[46] = {0, 1};
    for(int i=2; i<46; i++) dp[i] = dp[i-1] + dp[i-2];
    int n; cin >> n;
    cout << dp[n];
    
    return 0;
}
