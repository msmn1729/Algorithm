#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> places;
vector<pair<int, int>> people;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(int t, int idx) {
    int dist[10][10] = {};
    memset(dist, -1, sizeof(dist));
    queue<pair<int, int>> q;
    q.push(people[idx]);
    dist[people[idx].first][people[idx].second] = 0;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second; q.pop();
        
        for(int dir=0; dir<4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx<0 || ny<0 || nx>=5 || ny>=5) continue;
            if(places[t][nx][ny] == 'X') continue;
            if(dist[nx][ny] >= 0) continue;
            dist[nx][ny] = dist[x][y] + 1;
            
            // 새로 방문한 곳이 사람이 있으면서 거리가 2이하인 경우 0리턴
            if(places[t][nx][ny] == 'P' && dist[nx][ny] <= 2) return 0;
            q.push({nx, ny});
        }
    }
    return 1;
}

// 각 테스트케이스 마다 거리두기 여부를 반환
int solve(int t) {
    // 사람좌표를 페어에 다 집어넣고 맨해튼 거리를 구함
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            if(places[t][i][j] == 'P') people.push_back({i, j});
        }
    }
    int flag = 1;
    // 사람 수 만큼 bfs 호출
    for(int i=0; i<people.size(); i++) {
        flag = bfs(t, i);
        if(flag == 0) break;
    }
    people.clear(); // 한 케이스가 끝나면 초기화
    return flag;
}

vector<int> solution(vector<vector<string>> input_places) {
    vector<int> answer;
    places = input_places;
    for(int t=0; t<5; t++) answer.push_back(solve(t));
    return answer;
}