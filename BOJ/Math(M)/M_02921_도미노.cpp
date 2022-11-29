#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, ans = 0;
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=i; j++) {
            ans += i+j;
        }
    }
    cout << ans;
    
    return 0;
}
