#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct info {
    int x, y, dir;
};

int dx[4] = {-1, 0, 1, 0}; // 북동남서
int dy[4] = {0, 1, 0, -1};
int h, w;
int visit[30][30];
info ans, start;
string ar[30];
vector<pair<int, int> > cand;
string ansCmd;

void go(info cur, int cnt, string cmd) {
    if(cnt == cand.size()) {
        if(ansCmd == "" || ansCmd.size() > cmd.size()) {
            ans = start;
            ansCmd = cmd;
        }
        return;
    }
    
    for(int i=0; i<4; i++) {
        int x = cur.x, y = cur.y, dir = cur.dir;
        int ndir = (dir+i)%4; // 우회전
        
        string nxt = "A";
        if(i == 1) nxt = "RA";
        else if(i == 2) nxt = "RRA";
        else if(i == 3) nxt = "LA";
        
        int nx1 = x + dx[ndir], nx2 = x + 2*dx[ndir];
        int ny1 = y + dy[ndir], ny2 = y + 2*dy[ndir];
        if(nx1<0 || ny1<0 || nx1>=h || ny1>=w) continue;
        if(nx2<0 || ny2<0 || nx2>=h || ny2>=w) continue;
        if(visit[nx1][ny1] || visit[nx2][ny2]) continue;
        if(ar[nx1][ny1] == '.' || ar[nx2][ny2] == '.') continue;
        
        visit[nx1][ny1] = visit[nx2][ny2] = 1;
        go({nx2, ny2, ndir}, cnt + 2, cmd + nxt);
        visit[nx1][ny1] = visit[nx2][ny2] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> h >> w;
    for(int i=0; i<h; i++) {
        cin >> ar[i];
        for(int j=0; j<w; j++) {
            if(ar[i][j] == '#') cand.push_back({i, j});
        }
    }
    
    for(auto [x, y] : cand) {
        for(int i=0; i<4; i++) {
            start = {x, y, i};
            visit[x][y] = 1;
            go({0, 0, i}, 1, "");
            memset(visit, 0, sizeof(visit));
        }
    }
    
    cout << ans.x + 1 << ' ' << ans.y + 1 << '\n';
    if(ans.dir == 0) cout << "^\n";
    if(ans.dir == 1) cout << ">\n";
    if(ans.dir == 2) cout << "v\n";
    if(ans.dir == 3) cout << "<\n";
    cout << ansCmd;
    
    return 0;
}
