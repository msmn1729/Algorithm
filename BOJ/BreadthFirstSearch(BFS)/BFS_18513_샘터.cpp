#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/18513 샘터

int dx[2] = {-1, 1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, k;
    unordered_map<int, int> visit;
    queue<pii> q;
    cin >> n >> k;
    
    for(int i=0; i<n; i++) {
        int pos;
        cin >> pos;
        q.push({pos, 0});
        visit[pos] = 1;
    }
    
    ll ans = 0;
    while(!q.empty()) {
        int x = q.front().first;
        int cur_dist = q.front().second;
        q.pop();
        
        for(int dir=0; dir<2; dir++) {
            int nx = x + dx[dir];
            if(visit[nx]) continue;
            visit[nx] = 1;
            q.push({nx, cur_dist + 1});
            ans += cur_dist + 1;
            
            if(--k == 0) {
                cout << ans;
                return 0;
            }
        }
    }
    
    return 0;
}
