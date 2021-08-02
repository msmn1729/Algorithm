#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/14867 물통

map<int, int> m[101010];
queue<pii> q;

void pour(int nx, int ny) {
    if(m[nx][ny]) return;
    m[nx][ny] = 1;
    q.push({nx, ny});
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    q.push({0, 0});
    
    int ans = 0;
    while(!q.empty()) {
        int q_size = (int)q.size();
        
        while(q_size--) {
            int x = q.front().first;
            int y = q.front().second; q.pop();
            
            if(x == c && y == d) {
                cout << ans;
                return 0;
            }
            
            // 1. 가득 채우기
            pour(a, y);
            pour(x, b);
            
            // 2. 모두 버리기
            pour(x, 0);
            pour(0, y);
            
            // 3. 물 옮기기
            // 3-1. x->y
            int water = min(x, b - y);
            pour(x - water, y + water);
            
            // 3-2. y->x
            water = min(a - x, y);
            pour(x + water, y - water);
        }
        ans++;
    }
    cout << -1;
    
    return 0;
}
