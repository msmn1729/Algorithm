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

//https://www.acmicpc.net/problem/2638 치즈
//2636 치즈보다 어려운 문제
//구멍 뚫린 부분을 어떻게 처리할지 생각

int r, c;
int board[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int melt_cnt;

//치즈가 없는 부분을 dfs
void bfs()
{
    int visit[101][101] = {}; //함수를 부를 때 마다 visit 초기화 필요
    queue<pair<int, int> > q;
    int x=0, y=0;
    q.push({x, y});
    visit[x][y] = 1; //방문처리
    
    while(q.size())
    {
        auto cur = q.front(); q.pop();
        for(int div=0; div<4; div++)
        {
            int nx = cur.first + dx[div];
            int ny = cur.second + dy[div];
            if(nx<0 || ny<0 || nx>=r || ny>=c) continue;
            if(visit[nx][ny] || board[nx][ny]) continue; //방문했었거나 치즈를 만나면 패스
            visit[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
    
    //치즈를 녹이는 부분
    int i, j;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(!board[i][j]) continue; //치즈가 아니면 패스
            int part_cnt=0;
            for(int div=0; div<4; div++)
            {
                int ni = i + dx[div];
                int nj = j + dy[div];
                if(!visit[ni][nj]) continue; //인접한 치즈가 있으면 패스 보드쓰면 안됨?
                part_cnt++; //공기와 접촉하는 부분 카운팅
            }
            if(part_cnt >= 2)
            {
                board[i][j] = 0; //치즈 녹임
                melt_cnt++; //녹인 치즈 개수
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> r >> c;
    int i, j, cheese_cnt=0, ans=0;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            cin >> board[i][j];
            if(board[i][j]) cheese_cnt++;
        }
    }
    while(cheese_cnt > melt_cnt)
    {
        bfs();
        ans++;
    }
    cout << ans;
    
    return 0;
}
