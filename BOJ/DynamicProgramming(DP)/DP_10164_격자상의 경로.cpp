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

//https://www.acmicpc.net/problem/10164 격자상의 경로

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int r, c, k, i, j;
    int dp[16][16] = {};
    
    cin >> r >> c >> k;
    for(i=0; i<=15; i++)
    {
        dp[i][0] = dp[0][i] = 1; //가로, 세로가 1인 사각형은 경우의 수가 1
    }
    
    for(i=1; i<=15; i++)
    {
        for(j=1; j<=15; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    
    int x = (k-1)/ c; //k의 행
    int y = (k-1) % c; //k의 열
    if(k) cout << dp[x][y] * dp[r-1-x][c-1-y];
    else cout << dp[r-1][c-1];
    
    return 0;
}
