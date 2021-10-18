#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int ans = 0;
    vector<pair<int, int> > v;
    int w, n, m, p;
    cin >> w >> n;
    
    while(n--) {
        cin >> m >> p;
        v.push_back({p, m});
    }
    sort(v.begin(), v.end(), greater<>());
    
    for(int i=0; i<v.size(); i++) {
        m = v[i].second;
        p = v[i].first;
        int mn = min(w, m);
        w -= mn;
        ans += mn * p;
    }
    cout << ans;
    
    return 0;
}
