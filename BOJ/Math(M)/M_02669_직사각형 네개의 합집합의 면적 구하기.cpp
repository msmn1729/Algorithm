#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ar[101][101] = {};
    int n = 4;
    int x1, y1, x2, y2;
    
    for(int k=0; k<n; k++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i=x1; i<x2; i++) {
            for(int j=y1; j<y2; j++) {
                ar[i][j] = 1;
            }
        }
    }
    
    int ans = 0;
    for(int i=0; i<=100; i++) {
        for(int j=0; j<=100; j++) {
            ans += ar[i][j];
        }
    }
    cout << ans;
    
    return 0;
}
