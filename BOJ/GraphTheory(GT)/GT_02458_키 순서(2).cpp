#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/2458 키 순서

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m, ans = 0;
    int ar[501][501] = {};
    cin >> n >> m;
    
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        ar[a][b] = 1;
    }

    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                // ar[a][b]: a보다 b가 큰 관계일 때 1
                if(ar[i][k] && ar[k][j]) ar[i][j] = 1;
            }
        }
    }
    
    for(int i=1; i<=n; i++) {
        int cnt = 1;
        for(int j=1; j<=n; j++) {
            if(ar[i][j] || ar[j][i]) cnt++;
        }
        if(cnt == n) ans++;
    }
    cout << ans;
    
    return 0;
}
