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
#include <unordered_map>
#include <bitset>
#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/14502 연구소

int r, c;
int virus_min_cnt = 2e9;
int board[10][10];
int visit[10][10];
vector<pair<int, int> > v;

int dfs(int x, int y) {
    if(x<0 || y<0 || x>=r || y>=c || board[x][y] == 1|| visit[x][y] == 1) return 0;
    visit[x][y] = 1;
    return 1 + dfs(x-1, y) + dfs(x, y-1) + dfs(x+1, y) + dfs(x, y+1);
}

//바이러스에 감염된 칸 수를 반환하는 함수
int spread_virus() {
    int virus_sum = 0;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(board[i][j] == 2) {
                virus_sum += dfs(i, j);
            }
        }
    }
    return virus_sum;
}

void buildWall(int wall_cnt) {
    if(wall_cnt == 3) {
        memset(visit, 0, sizeof(visit));
        virus_min_cnt = min(virus_min_cnt, spread_virus());
        return;
    }
    for(int i=0; i<v.size(); i++) {
        int nx = v[i].first;
        int ny = v[i].second;
        if(board[nx][ny]) continue;
        board[nx][ny] = 1;
        buildWall(wall_cnt+1);
        board[nx][ny] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int one_cnt = 0;
    cin >> r >> c;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> board[i][j];
            one_cnt += (board[i][j] == 1);
            if(board[i][j] == 0) v.push_back({i, j});
        }
    }
    
    buildWall(0);
    
    int ans = r * c - one_cnt - virus_min_cnt - 3;
    cout << ans;
    
    return 0;
}
