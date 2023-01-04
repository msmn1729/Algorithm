#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, p, m;
    cin >> t;
    
    while(t--) {
        cin >> p >> m;
        int visited[501] = {};
        int ans = 0;
        
        for(int i=0; i<p; i++) {
            int in;
            cin >> in;
            if(visited[in]) ans++;
            else visited[in] = 1;
        }
        cout << ans << '\n';
    }
    
    return 0;
}
