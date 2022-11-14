#include <bits/stdc++.h>
#define ull unsigned long long
#define INF 1e9
#define MOD 1000000007
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ull n;
    cin >> n;
    ull ans = (n*(n+1)/2) % MOD;
    ans = (ans * ans) % MOD;
    cout << ans;
    
    return 0;
}
