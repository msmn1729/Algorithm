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

long long n, hp;
int board[1001][1001];
long long dist[1001][1001];
bool visit[1001][1001];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void solve()
{
    priority_queue< pair<long long, pair<long long, long long> > > pq;
    pq.push( { board[0][0], {0, 0} } );
    dist[0][0] = board[0][0];
//    visit[0][0] = true;
    
    while(pq.size())
    {
        long long cost = pq.top().first;
        long long x = pq.top().second.first;
        long long y = pq.top().second.second;
        pq.pop();
        
        for(int div=0; div<4; div++)
        {
            long long nx = x + dx[div];
            long long ny = y + dy[div];
            if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
//            if(dist[x][y] + board[nx][ny] >= hp) continue;
            
            long long next_cost = cost + board[nx][ny];
//            if(next_cost >= hp) continue; //누적합이 체력이상이면 패스
            if(dist[nx][ny] <= next_cost) continue; //패스
//            visit[nx][ny] = true;
            dist[nx][ny] = next_cost;
            pq.push({dist[nx][ny], {nx, ny}});
        }
    }
    hp -= dist[n-1][n-1];
    
    
    //출력확인
//    cout << "\n\n\n";
//    for(int i=0; i<n; i++)
//    {
//        for(int j=0; j<n; j++)
//        {
//            cout << dist[i][j] << ' ';
//        }
//        cout << '\n';
//    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> hp;
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cin >> board[i][j];
            dist[i][j] = 987654321;
//            visit[i][j] = false;
        }
    }
    solve();
    if(hp > 0) cout << hp;
    else cout << -1;
    
    return 0;
}
