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
//
//using namespace std;
//string board[102];
//int dist[102][102];
//
//int n, m;
//int dx[4] = {-1, 1, 0, 0};
//int dy[4] = {0, 0, -1, 1};
//int main()
//{
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//    
//    cin >> n >> m;
//    int i;
//    for(i=0; i<n; i++)
//        cin >> board[i];
//    
//    queue<pair<int, int> > Q;
//    Q.push({0, 0});
//    dist[0][0] = 1;
//    
//    while(!Q.empty())
//    {
//        auto cur = Q.front(); //맨 앞에 있는것이 현재
//        Q.pop();
//        for(int div=0; div<4; div++)
//        {
//            int nx = cur.first + dx[div];
//            int ny = cur.second + dy[div];
//            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
//            if(dist[nx][ny] || board[nx][ny] == '0') continue; //방문을 했던 곳이거나 막힌길이면 패스
//            dist[nx][ny] = dist[cur.first][cur.second] + 1; //이전보다 거리 +1
//            Q.push({nx, ny}); //큐에 현재 위치 푸쉬
//        }
//    }
//    cout << dist[n-1][m-1];
//}
