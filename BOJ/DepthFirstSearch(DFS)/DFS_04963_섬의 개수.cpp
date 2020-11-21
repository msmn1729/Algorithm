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

//https://www.acmicpc.net/problem/4963 섬의 개수

int r, c;
int board[51][51];

int dfs(int x, int y)
{
    if(x<0 || y<0 || x>=r || y>=c || !board[x][y]) return 0;
    board[x][y] = 0;
    return 1 + dfs(x+1, y) + dfs(x-1, y) + dfs(x, y+1) + dfs(x, y-1)
    + dfs(x-1, y-1) + dfs(x-1, y+1) + dfs(x+1, y-1) + dfs(x+1, y+1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int i, j;
    while(1)
    {
        int ans = 0;
        cin >> c >> r;
        if(!r && !c) break;
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++) cin >> board[i][j];
        }
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                if(board[i][j])
                {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        cout << ans << '\n';
        
        memset(board, 0, sizeof(board));
    }
    return 0;
}
