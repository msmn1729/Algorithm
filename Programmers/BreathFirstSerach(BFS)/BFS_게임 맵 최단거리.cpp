#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#define ll long long
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int dist[101][101];

int solution(vector<vector<int> > maps) {
    int n = (int)maps.size();
    int m = (int)maps[0].size();
    
    // dist 배열 초기화
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            dist[i][j] = -1;
        }
    }
    
    // 큐에 좌표 삽입
    queue<pair<int, int> > q;
    q.push({0, 0});
    dist[0][0] = 1;
    
    while(q.size()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        for(int dir=0; dir<4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(dist[nx][ny] != -1 && dist[nx][ny] <= dist[cx][cy] + 1) continue;
            if(!maps[nx][ny]) continue;
            dist[nx][ny] = dist[cx][cy] + 1;
            q.push({nx, ny});
        }
    }
    
    return dist[n-1][m-1];
}

int main() {
    solution({{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1}});
    
    return 0;
}
