#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <iomanip>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/7576 토마토

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int ar[1001][1001] = {};
    int dist[1001][1001] = {};
    int r, c;
    queue<pair<int, int> > q;
    cin >> c >> r;
    
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> ar[i][j];
            if(ar[i][j] == 1) q.push({i, j});
            else if(ar[i][j] == 0) dist[i][j] = -1; // 방문할 좌표들 -1로 초기화
        }
    }
    
    int ans = 0;
    while(q.size()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int dir=0; dir<4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx<0 || ny<0 || nx>=r || ny>=c) continue;
            if(dist[nx][ny] >= 0) continue; // 0인 경우는 빈칸인 곳이라 갈 수가 없음
            
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(dist[i][j] == -1) {
                cout << -1;
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans;
    
    return 0;
}
