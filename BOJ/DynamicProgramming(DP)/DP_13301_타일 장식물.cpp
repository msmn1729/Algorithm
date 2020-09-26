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

//https://www.acmicpc.net/problem/13301 타일 장식물

ll dp[80] = {};

ll fibo(ll a)
{
    if(a < 2) return 1;
    if(dp[a]) return dp[a];
    return dp[a] = fibo(a-1) + fibo(a-2);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    cout << (fibo(n)+fibo(n-1))*2;
    return 0;
}
