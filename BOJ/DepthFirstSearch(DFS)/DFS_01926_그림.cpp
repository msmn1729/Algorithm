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

//https://www.acmicpc.net/problem/1926 그림

int r, c, cnt, ans1, ans2;
int board[500][500];

int dfs(int x, int y)
{
    if(x<0 || y<0 || x>=r || y>=c || !board[x][y]) return 0;
    board[x][y] = 0;
    return 1 + dfs(x-1, y) + dfs(x+1, y) + dfs(x, y-1) + dfs(x, y+1);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ans1 = 0, ans2 = 0;
    int i, j;
    cin >> r >> c;
    
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            cin >> board[i][j];
        }
    }
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(board[i][j])
            {
                ans1++;
                ans2 = max(ans2, dfs(i, j));
            }
        }
    }
    cout << ans1 << '\n' << ans2;
    
    return 0;
}
