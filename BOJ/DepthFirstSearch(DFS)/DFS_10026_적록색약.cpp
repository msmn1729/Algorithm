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

//https://www.acmicpc.net/problem/10026 적록색약
//수월하게 클리어!

int board[101][101], board2[101][101];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int n;

void dfs(int x, int y, int a, int b)
{
    if(x<0 || y<0 || x>=n || y>=n || board[x][y] == a || board[x][y] == b || board[x][y] == -1) return;
    board[x][y] = -1;
    for(int i=0; i<4; i++)
    {
        dfs(x+dx[i], y+dy[i], a, b);
    }
}
void dfs2(int x, int y, int a)
{
    if(x<0 || y<0 || x>=n || y>=n || board2[x][y] == a || board2[x][y] == -1) return;
    board2[x][y] = -1;
    for(int i=0; i<4; i++)
    {
        dfs2(x+dx[i], y+dy[i], a);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            char c;
            cin >> c;
            if(c == 'R') board[i][j] = board2[i][j] = 1;
            else if(c == 'G')
            {
                board[i][j] = 2;
                board2[i][j] = 1; //적록색약은 빨간색과 구분 불가
            }
            else if(c == 'B') board[i][j] = board2[i][j] = 3;
        }
    }
    int ans=0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(board[i][j] == 1) //red
            {
                dfs(i, j, 2, 3);
                ans++;
            }
            else if(board[i][j] == 2) //green
            {
                dfs(i, j, 1, 3);
                ans++;
            }
            else if(board[i][j] == 3) //blue
            {
                dfs(i, j, 1, 2);
                ans++;
            }
        }
    }
    
    //적록색약
    int ans2=0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(board2[i][j] == 1) //red, green 모두 1
            {
                dfs2(i, j, 3);
                ans2++;
            }
            else if(board2[i][j] == 3) //blue
            {
                dfs2(i, j, 1);
                ans2++;
            }
        }
    }
    cout << ans << ' ' << ans2;

    return 0;
}
