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

using namespace std;
int board[502][502];
bool vis[502][502];
int n, m;
int dx[4] = {1, 0 , -1, 0};
int dy[4] = {0, 1, 0, -1};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i, j;
    cin >> n >> m;
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            cin >> board[i][j];
    int mx = 0; //그림의 최대넓이
    int num = 0; //그림의 수
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(board[i][j] == 0 || vis[i][j]) continue; //빈 곳이거나 방문했던 곳이면 패스
            num++;
            queue<pair<int, int> > Q;
            vis[i][j] = 1; //방문 표시
            Q.push({i, j}); //큐에 좌표 푸쉬
            int area = 0; //넓이
            while(!Q.empty())
            {
                area++;
                pair<int, int> cur = Q.front(); //현재위치
                Q.pop();
                for(int dir=0; dir<4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(vis[nx][ny] || board[nx][ny] != 1) continue; //방문했거나 빈 곳이면 패스
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            mx = max(area, mx); //가장 큰 넓이 반환
        }
    }
    cout << num << '\n' << mx;
}
