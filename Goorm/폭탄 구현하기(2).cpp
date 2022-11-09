#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int dx[5] = {0, -1, 0, 1, 0};
int dy[5] = {0, 0, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    int ans = 5*k;
    
    for(int i=0; i<k; i++) {
        int x, y;
        cin >> x >> y;
        for(int dir=0; dir<5; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx<1 || ny<1 || nx>n || ny>n) ans--;
        }
    }
    cout << ans;
    
    return 0;
}
