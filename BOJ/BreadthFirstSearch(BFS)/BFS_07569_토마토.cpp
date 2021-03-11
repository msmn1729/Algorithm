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

//https://www.acmicpc.net/problem/7569 토마토

int dx[6] = {-1, 0, 1, 0, 0, 0};
int dy[6] = {0, -1, 0, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

struct loc{
    int z, x, y;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int ar[101][101][101] = {};
    int dist[101][101][101] = {};
    int r, c, h;
    queue<loc> q;
    cin >> c >> r >> h;
    
    for(int k=0; k<h; k++) {
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                cin >> ar[k][i][j];
                if(ar[k][i][j] == 1) q.push({k, i, j}); //익은 토마토 좌표 삽입
                else if(ar[k][i][j] == 0) dist[k][i][j] = -1; //방문할 좌표들 -1로 초기화
            }
        }
    }
    
    int ans = 0;
    while(q.size()) {
        int z = q.front().z;
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        
        for(int dir=0; dir<6; dir++) {
            int nz = z + dz[dir];
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx<0 || ny<0 || nz<0 || nx>=r || ny>=c || nz>=h) continue;
            if(dist[nz][nx][ny] >= 0) continue;
            
            dist[nz][nx][ny] = dist[z][x][y] + 1;
            q.push({nz, nx, ny});
        }
    }
    for(int k=0; k<h; k++) {
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(dist[k][i][j] == -1) {
                    cout << -1;
                    return 0;
                }
                ans = max(ans, dist[k][i][j]);
            }
        }
    }
    cout << ans;
    
    return 0;
}
