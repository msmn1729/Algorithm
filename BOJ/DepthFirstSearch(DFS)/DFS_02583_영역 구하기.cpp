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

//https://www.acmicpc.net/problem/2583 영역 구하기

int board[101][101];
int m, n, k;

int dfs(int x, int y)
{
    if(x < 0 || y < 0 || x >= m || y >= n || board[x][y] == 1) return 0;
    board[x][y] = 1;
    return 1 + dfs(x-1, y) + dfs(x+1, y) + dfs(x, y-1) + dfs(x, y+1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n >> k;
    int i, j;
    for(i=0; i<k; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for(int j=a; j<c; j++)
        {
            for(int l=b; l<d; l++)
            {
                board[m-l-1][j] = 1;
            }
        }
    }
    vector<int> area;
    for(j=0; j<n; j++)
    {
        for(i=0; i<m; i++)
        {
            if(board[i][j] == 0)
            {
                area.push_back(dfs(i, j));
            }
        }
    }
    cout << area.size() << '\n';
    sort(area.begin(), area.end());
    for(auto i: area) cout << i << ' ';

    return 0;
}
