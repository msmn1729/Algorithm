#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int vis1[30]; // 가로
int vis2[30]; // 대각
int vis3[30]; // 역대각
int n, ans;

void dfs(int x) {
    if(x == n) {
        ans++;
        return;
    }
    
    for(int y=0; y<n; y++) {
        if(vis1[y] || vis2[n+x-y] || vis3[x+y]) continue;
        vis1[y] = vis2[n+x-y] = vis3[x+y] = 1;
        dfs(x+1);
        vis1[y] = vis2[n+x-y] = vis3[x+y] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    dfs(0);
    cout << ans;

    return 0;
}
