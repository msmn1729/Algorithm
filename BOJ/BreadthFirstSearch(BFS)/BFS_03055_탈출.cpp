#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://www.acmicpc.net/problem/3055 탈출

typedef pair<int, int> pii;
int r, c;
char forest[51][51];
int ddg_dist[51][51];
int water_dist[51][51];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
pii ddg;
vector<pii> water;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> r >> c;
    for(int i=0; i<r; i++) {
        cin >> forest[i];
        for(int j=0; j<c; j++) {
            if(forest[i][j] == 'S') ddg = {i, j};
            else if(forest[i][j] == '*') water.push_back({i, j});
        }
    }
    
    // 미방문 전처리
    for(int i=0; i<r; i++) fill(ddg_dist[i], ddg_dist[i]+c, -1);
    for(int i=0; i<r; i++) fill(water_dist[i], water_dist[i]+c, -1);
    
    queue<pair<int, int>> ddg_q, water_q;
    ddg_q.push({ddg.first, ddg.second});
    ddg_dist[ddg.first][ddg.second] = 0;
    for(auto it : water) {
        water_q.push({it.first, it.second});
        water_dist[it.first][it.second] = 0;
    }
    
    // 물 bfs
    while(!water_q.empty()) {
        pii cur = water_q.front();
        water_q.pop();
        for(int dir=0; dir<4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx<0 || ny<0 || nx>=r || ny>=c) continue;
            if(forest[nx][ny] == 'X' || forest[nx][ny] == 'D') continue; // 돌이거나 비버는 패스
            if(water_dist[nx][ny] >= 0) continue;
            water_dist[nx][ny] = water_dist[cur.first][cur.second] + 1;
            water_q.push({nx, ny});
        }
    }
    
    // 두더지 bfs
    while(!ddg_q.empty()) {
        pii cur = ddg_q.front();
        ddg_q.pop();
        
        if(forest[cur.first][cur.second] == 'D') {
            cout << ddg_dist[cur.first][cur.second];
            return 0;
        }
        
        for(int dir=0; dir<4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx<0 || ny<0 || nx>=r || ny>=c) continue;
            if(forest[nx][ny] == 'X') continue; // 돌인 경우 패스
            if(ddg_dist[nx][ny] >= 0) continue;
            if(water_dist[nx][ny] != -1 && (water_dist[nx][ny] <= ddg_dist[cur.first][cur.second] + 1)) continue;
            ddg_dist[nx][ny] = ddg_dist[cur.first][cur.second] + 1;
            ddg_q.push({nx, ny});
        }
    }
    cout << "KAKTUS";
    
    return 0;
}
