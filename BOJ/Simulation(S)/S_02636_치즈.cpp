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

//https://www.acmicpc.net/problem/2636 치즈

int m, n, cnt, cheese_minus;
int board[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs()
{
    int i, j;
    int cheese_minus = 0;
    int r_visit[101][101] = {};
    for(i=0; i<m; i++) fill(r_visit[i], r_visit[i]+n, 1); //1로 채움
    
    queue<pair<int, int> > q;
    int x=0, y=0;
    
    q.push({x, y});
    r_visit[x][y] = 0;
    
    //bfs로 치즈가 아닌 부분을 방문 처리
    while(q.size())
    {
        auto cur = q.front(); q.pop();
        for(int div=0; div<4; div++)
        {
            int nx = cur.first + dx[div];
            int ny = cur.second + dy[div];
            if(nx<0 || ny<0 || nx>=m || ny>=n) continue;
            if(!r_visit[nx][ny] || board[nx][ny]) continue; //방문했거나 치즈인 곳 패스
            r_visit[nx][ny] = 0;
            q.push({nx, ny});
        }
    }
    
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if(board[i][j] == 0) continue; //공기 패스
            for(int div=0; div<4; div++)
            {
                int ni = i + dx[div];
                int nj = j + dy[div];
                if(r_visit[ni][nj]) continue; //인접한 치즈가 있으면 패스
                board[i][j] = 0; //치즈를 공기로 바꿈
                cheese_minus++; //뺄 치즈 개수
                break; //치즈 하나만 지우고 빠져나감
            }
        }
    }
    return cheese_minus;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> m >> n;
    int i, j;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            cin >> board[i][j];
            if(board[i][j]) cnt++; //치즈 카운팅
        }
    }
    
    int ans_time=0, prev_cheese=0, sum=0;
    while(1)
    {
        ans_time++;
        prev_cheese = bfs(); //지운 치즈 개수 저장
        sum += prev_cheese; //지운 치즈 수를 합함
        if(sum >= cnt) break; //합이 전체 치즈 수 이상이면 탈출
//        cout << "\n\n------------------------------------------\n\n";
//
//        for(i=0; i<m; i++)
//        {
//            for(j=0; j<n; j++)
//            {
//                cout << board[i][j] << ' ';
//            }
//            cout << '\n';
//        }
    }
    cout << ans_time << '\n' << prev_cheese;
    
    return 0;
}
