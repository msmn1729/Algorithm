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

//https://www.acmicpc.net/problem/2234 성곽

int r, c, ans1, ans2, ans3; //ans1 : 방의 개수, ans2 : 가장 넓은 방의 넓이, ans3 : 하나의 벽을 제거해서 얻을 수 있는 가장 넓은 방의 크기
int board[50][50], visit[50][50], area[2500];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int dfs(int x, int y, int z)
{
    visit[x][y] = z;
    int res = 1;
    for (int i=0; i<4; i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if ((board[x][y] & (1<<i)) || visit[nx][ny]) continue; //벽이거나 방문한 곳이면 패스
        res += dfs(nx, ny, z);
    }
    return res;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int i, j, k;
    cin >> c >> r;
    
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
            if(visit[i][j]) continue;
            ans1++; //방의 개수 카운팅
            int tmp = dfs(i, j, ans1);
            if(ans2 < tmp) ans2 = tmp;
            area[ans1] = tmp;
        }
    }
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            for(k=0; k<4; k++)
            {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni < 0 || ni >= r || nj < 0 || nj >= c) continue;
                int x = visit[i][j];
                int y = visit[ni][nj];
                if (x != y)
                {
                    int sum = area[x] + area[y];
                    if (ans3 < sum) ans3 = sum;
                }
            }
        }
    }
    cout << ans1 << '\n' << ans2 << '\n' << ans3;
    
    return 0;
}
