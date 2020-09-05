//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cstring>
//#include <queue>
//#include <string>
//#include <map>
//#include <iomanip>
//#include <list>
//#include <stack>
//#include <cstring>
//#include <cmath>
//#include <set>
//
//using namespace std;
//
//
//int n;
//int dx[4] = {-1, 1, 0, 0};
//int dy[4] = {0, 0, -1, 1};
//int main()
//{
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//
//    int board[510][510] = {}, dist[510][510] = {}, hong_dist[510][510] = {};
//    int ori_dist[510][510] = {}, one_cnt=0;
//    cin >> n;
//    int i, j;
//    for(i=0; i<n; i++)
//    {
//        for(j=0; j<n; j++)
//        {
//            cin >> board[i][j];
//            if(board[i][j] == 0) //갈 수 있는 곳
//            {
//                hong_dist[i][j] = ori_dist[i][j] = dist[i][j] = -1; //가야할 곳
//            }
//            else if(board[i][j]) one_cnt++;
//        }
//    }
//    for(i=0; i<n; i++)
//    {
//        for(j=0; j<n; j++)
//        {
//            hong_dist[i][j] = -1; //홍현이는 모든 곳을 감
//        }
//    }
//
//
//
//    //bfs
//    int ans = 0;
//
//    queue<pair<int, int> > Q;
//    Q.push({0, 0}); //시작 점
//    dist[0][0] = 1;
//
//    //물 bfs
//    while(!Q.empty())
//    {
//        auto cur = Q.front();
//        Q.pop();
//        for(int div=0; div<4; div++)
//        {
//            int nx = cur.first + dx[div];
//            int ny = cur.second + dy[div];
//
//            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
//            //방문했었거나(dist>0) 없는 곳(dist==0)이거나 물이 못가는 곳이면
//            if(dist[nx][ny] >= 0 || board[nx][ny] == 1) continue;
//            dist[nx][ny] = dist[cur.first][cur.second] + 1;
//            //ans = max(ans, dist[nx][ny]);
//            Q.push({nx, ny});
//        }
//    }
//
//    //홍현 bfs
//    queue<pair<int, int> > hong_Q;
//    hong_Q.push({n-1, n-1}); //시작 점
//    hong_dist[n-1][n-1] = 1;
//
//    while(!hong_Q.empty())
//    {
//        auto hong_cur = hong_Q.front();
//        hong_Q.pop();
//        for(int div=0; div<4; div++)
//        {
//            int nx = hong_cur.first + dx[div];
//            int ny = hong_cur.second + dy[div];
//
//            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
//            if(hong_dist[nx][ny] >= 0 || board[nx][ny] == 1) continue;
//            //홍현이는 1을 갈 수 있다고 가정
////            if(hong_dist[nx][ny] >= 0) continue;
//            hong_dist[nx][ny] = hong_dist[hong_cur.first][hong_cur.second] + 1;
//            hong_Q.push({nx, ny});
//        }
//    }
//
//
//    //홍현이 설치할 수 있는 모든 경우 벽 설치
//    for(i=0; i<n; i++)
//    {
//        for(j=0; j<n; j++)
//        {
//            if(i == n-1 && j == n-1) continue; //홍현 시작점에 벽설치 불가
//            if(dist[i][j] <= hong_dist[i][j]) //홍현이 물보다 늦은 경우
//                continue;
////            cout << i << ' ' << j << '\n';
//
//            board[i][j] = 1; //물이 지나갈 수 없게
//
//            for(int x=0; x<n; x++)
//            {
//                for(int y=0; y<n; y++)
//                {
//                    dist[x][y] = ori_dist[x][y];
//                }
//            }
//
//            queue<pair<int, int> > Q2;
//            Q2.push({0, 0}); //시작 점
//            dist[0][0] = 1;
//
//            //물 bfs
//            while(!Q2.empty())
//            {
//                auto cur = Q2.front();
//                Q2.pop();
//                for(int div=0; div<4; div++)
//                {
//                    int nx = cur.first + dx[div];
//                    int ny = cur.second + dy[div];
//
//                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
//                    //방문했었거나(dist>0) 없는 곳(dist==0)이거나 물이 못가는 곳이면
//                    if(dist[nx][ny] >= 0 || board[nx][ny] == 1) continue;
//                    dist[nx][ny] = dist[cur.first][cur.second] + 1;
//                    //ans = max(ans, dist[nx][ny]);
//                    Q2.push({nx, ny});
//                }
//            }
//            cout << "------------------------------------\n\n";
//            cout << i << ", " << j << "에 벽설치 \n";
//            int cnt = 0;
//            for(int x=0; x<n; x++)
//            {
//                for(int y=0; y<n; y++)
//                {
//                    if(dist[x][y] == -1) cnt++;
//                    cout << dist[x][y] << ' ';
//                }
//                cout << '\n';
//            }
//            ans = max(ans, cnt-1);
//
//            board[i][j] = 0; //다시 물이 지나갈 수 있게
//        }
//    }
//
//    if(ans < 0 || ans >= n*n-2-one_cnt) cout << 0;
//    else cout << ans;
//    return 0;
//}
