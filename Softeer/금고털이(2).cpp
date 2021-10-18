#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int ans = 0;
    int w, n, m, p;
    int ar[10001] = {};
    cin >> w >> n;
    
    while(n--) {
        cin >> m >> p;
        ar[p] += m;
    }
    
    for(int i=10000; i>0; i--) {
        int mn = min(ar[i], w);
        ans += i * mn;
        w -= mn;
    }
    cout << ans;
    
    return 0;
}
