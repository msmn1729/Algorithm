#include<bits/stdc++.h>
using namespace std;

int n, ar[30][30];

int dfs(int x, int y) {
    if(x<0 || y<0 || x>=n || y>=n || ar[x][y] == 0) return 0;
    ar[x][y] = 0;
    return 1 + dfs(x-1, y) + dfs(x+1, y) + dfs(x, y-1) + dfs(x, y+1);
}

int main(int argc, char** argv) {
    cin >> n;
    string s;
    for(int i=0; i<n; i++) {
        cin >> s;
        for(int j=0; j<n; j++) {
            ar[i][j] = s[j] - '0';
        }
    }
    
    multiset<int> ans;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(ar[i][j]) ans.insert(dfs(i, j));
        }
    }

    cout << ans.size() << '\n';
    for(int it : ans) cout << it << '\n';

    return 0;
}
