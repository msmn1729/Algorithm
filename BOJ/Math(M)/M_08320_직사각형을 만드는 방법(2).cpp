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
    int ans = 0;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=sqrt(i); j++) {
            if(i%j == 0) ans++;
        }
    }
    cout << ans;

    return 0;
}
