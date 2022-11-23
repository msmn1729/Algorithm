#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    
    ans = max(ans, abs(a-b)-1);
    ans = max(ans, abs(b-c)-1);
    cout << ans;
    
    return 0;
}
