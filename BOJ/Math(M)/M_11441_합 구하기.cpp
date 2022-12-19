#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> v(n+1);
    
    for(int i=1; i<=n; i++) {
        int in;
        cin >> in;
        v[i] = v[i-1] + in;
    }
    
    int m;
    cin >> m;
    for(int i=0; i<m; i++) {
        int st, ed;
        cin >> st >> ed;
        cout << v[ed] - v[st-1] << '\n';
    }
    
    return 0;
}
