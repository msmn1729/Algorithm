#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    int board[101] = {}, dist[101] = {};
    int t = n+m;
    while(t--) {
        int cur, nxt;
        cin >> cur >> nxt;
        board[cur] = nxt;
    }
    fill(dist, dist+101, -1);
    
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    
    while(q.size()) {
        int cur = q.front();
        q.pop();
        if(cur == 100) {
            cout << dist[cur];
            break;
        }
        for(int i=1; i<=6; i++) {
            int nxt = cur+i;
            if(nxt > 100) continue;
            if(board[nxt]) nxt = board[nxt]; // 이동가능하면 이동
            if(dist[nxt] >= 0) continue; // 방문했던곳은 패스
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }
    return 0;
}
