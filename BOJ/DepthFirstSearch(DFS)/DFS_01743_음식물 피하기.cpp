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

//https://www.acmicpc.net/problem/1743 음식물 피하기

int board[101][101];
int r, c;

int dfs(int x, int y)
{
    if(x<1 || y<1 || x>r || y>c || !board[x][y]) return 0; //범위를 벗어나거나 음식물이 아닌 곳 패스
    board[x][y] = 0;
    return 1 + dfs(x-1, y) + dfs(x+1, y) + dfs(x, y-1) + dfs(x, y+1);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int k, i, j, x, y;
    cin >> r >> c >> k;
    
    while(k--)
    {
        cin >> x >> y;
        board[x][y] = 1; //음식물 좌표
    }
    
    int mx = -2e9;
    for(i=1; i<=r; i++)
    {
        for(j=0; j<=c; j++)
        {
            if(board[i][j])
            {
                mx = max(mx, dfs(i, j));
            }
        }
    }
    cout << mx;
    
    return 0;
}
