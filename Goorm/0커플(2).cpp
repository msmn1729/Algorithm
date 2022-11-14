#include <bits/stdc++.h>
#define ll unsigned long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, ans = 0;
    cin >> n;
    
    while(n--) {
        int num;
        cin >> num;
        ans += num;
    }
    cout << ans;
    
    return 0;
}
