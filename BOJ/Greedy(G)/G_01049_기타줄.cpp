#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    int minPackage = 2e9, minSingle = 2e9;
    
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        minPackage = min(minPackage, a);
        minSingle = min(minSingle, b);
    }
    
    int ans = (n/6)*minPackage + (n%6)*minSingle;
    ans = min(ans, minSingle*n);
    ans = min(ans, ((n-1)/6+1)*minPackage);
    cout << ans;
    
    return 0;
}
