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

//https://www.acmicpc.net/problem/1520 내리막 길
//dp와 dfs를 둘 다 활용할 수 있어야하는 문제

int board[501][501] = {}, dp[501][501] = {};
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int r, c;

int dfs(int x, int y)
{
    if(~dp[x][y]) return dp[x][y];
    if(x == 0 && y == 0) return dp[x][y] = 1;
    
    dp[x][y] = 0;
    for(int i=0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0 || ny<0 || nx>=r || ny>=c) continue;
        if(board[nx][ny] <= board[x][y]) continue;
        dp[x][y] += dfs(nx, ny);
    }
    return dp[x][y];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i, j;
    cin >> r >> c;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            cin >> board[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(r-1, c-1) << "\n\n\n";
    
//    for(i=0; i<r; i++)
//    {
//        for(j=0; j<c; j++)
//        {
//            cout << dp[i][j] << ' ';
//        }
//        cout << '\n';
//    }
    return 0;
}
