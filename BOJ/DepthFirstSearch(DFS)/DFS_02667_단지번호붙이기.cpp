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
#include <cstdlib>
#include <cmath>

using namespace std;

//https://www.acmicpc.net/problem/2667 단지번호붙이기 실버1

int board[26][26];
int groups[26 * 26];
int n;

int DFS(int x, int y)
{
    if(x < 0 || y < 0 || x >= n || y >= n || board[x][y] == 0) return 0;
    board[x][y] = 0;
    return 1 + DFS(x + 1, y) + DFS(x - 1, y) + DFS(x, y + 1) + DFS(x, y - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int i, j;
    string s;
    cin >> n;
    
    for(i=0; i<n; i++)
    {
        cin >> s;
        for(j=0; j<n; j++)
        {
            board[i][j] = s[j] - '0';
        }
    }
    int cnt = 0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(board[i][j] == 1)
            {
                groups[cnt++] = DFS(i, j);
            }
        }
    }
    cout << cnt << '\n';
    sort(groups, groups+cnt);
    for(i=0; i<cnt; i++) cout << groups[i] << '\n';
    
    return 0;
}
